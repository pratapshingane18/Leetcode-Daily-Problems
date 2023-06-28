class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> pro(n+1,-1e5);
        vector<pair<int,double>> adj[n+1];
        for(int i  = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        queue<pair<int,double>> q;
        q.push({start,1});
        pro[start] = 1;
        while(!q.empty()){
            auto node = q.front().first;
            auto p = q.front().second;
            q.pop();
            for(auto i: adj[node]){
                auto cnode = i.first;
                auto cp = i.second;
                if(p*cp>pro[cnode]){
                    pro[cnode] = p*cp;
                    q.push({cnode,pro[cnode]});
                }
            }
        }
        return pro[end]== -1e5 ? 0: pro[end];
    }
};
