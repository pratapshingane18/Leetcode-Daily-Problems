class Solution {
public:

    void dfs(int node,vector<pair<int,int>>adj[],int &cnt,vector<bool>&vis)
    {
        vis[node]=true;
        for(auto child:adj[node])
        {
            auto it=child.first;
            if(!vis[it])
            {
                if(child.second)
                {
                    cnt++;
                }
                dfs(it,adj,cnt,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& v) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<v.size();i++)
        {
            adj[v[i][0]].push_back({v[i][1],-1});
            adj[v[i][1]].push_back({v[i][0],0});
        }
        int cnt=0;
        vector<bool>vis(n,false);
        dfs(0,adj,cnt,vis);
        return cnt;

    }
};
