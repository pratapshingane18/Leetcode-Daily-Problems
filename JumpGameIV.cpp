class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> graph;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            graph[arr[i]].push_back(i);
        }
        auto isValid = [&] (const int _n) {
            return (_n >= 0 && _n < n);  
        };

        int steps = 0;
        queue<int> q;
  
        q.push(0);
        vector<bool> vis(n, 0);
        while(q.size() > 0) {
            int N = q.size();
            while(N--) {
                int node = q.front();
                q.pop();
                if (node == n - 1) return steps;
                for (int child: graph[arr[node]]) {
                    if (!vis[child]) {
                        q.push(child);
                        vis[child] = 1;
                    }
                }
                graph[arr[node]].clear();
                vis[node] = true;
                int dir[] = {-1, 1};
                for (int i = 0; i < 2; ++i) {
                    int _node = node + dir[i];
                    if (isValid(_node) && !vis[_node]) {
                        q.push(_node);
                        vis[_node] = 1;
                    }
                }
            }
            ++steps;
        }
        return steps;
    }
};
