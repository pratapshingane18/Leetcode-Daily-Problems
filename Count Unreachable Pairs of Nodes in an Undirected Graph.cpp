class Solution {
public:
    int totalNodesVisited = 0;
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, long long& countNodesVisited, int currNode) {
        visited[currNode] = true;
        totalNodesVisited++;
        countNodesVisited++;
        for (auto neighbourNode : adj[currNode]) {
            if (!visited[neighbourNode])
                dfs(adj, visited, countNodesVisited, neighbourNode);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        long long numOfPairs = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            long long countNodesVisited = 0;
            if (!visited[i]) {
                dfs(adj, visited, countNodesVisited, i);
            }
            numOfPairs += (countNodesVisited * (n - totalNodesVisited));
        }
        return numOfPairs;
    }
};
