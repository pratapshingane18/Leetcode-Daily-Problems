class Solution {
public:
    void dfs(vector<int>&vis,vector<vector<int>>&temp,int &t,int& i){
        vis[i]=1;
          t++;
        for(int j=0;j<temp[i].size();j++){
            if(!vis[temp[i][j]]){
                
                dfs(vis,temp,t,temp[i][j]);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>temp(n);

        for(int i=0;i<n;i++){
            long long x=bombs[i][0];
            long long y=bombs[i][1];
            long long r=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i!=j){
                    long long x1=abs(x-bombs[j][0]);
                    long long y1=abs(y-bombs[j][1]);
                    if(x1*x1+y1*y1<=r*r){
                        temp[i].push_back(j);
                    }
                }
            }
        }

       
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int t=0;
       vector<int>vis(n,0);
                dfs(vis,temp,t,i);
                ans=max(ans,t);
            
        }
        return ans;
    }
};
