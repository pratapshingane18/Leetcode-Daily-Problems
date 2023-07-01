class Solution {
public:
    int solve(int i,int k,vector<int> &child,vector<int>& cookies)
    {
        if(i==cookies.size())
            return *max_element(child.begin(),child.end());
        int ans=1e9;
        for(int c=0;c<k;c++)
        {
            child[c]+=cookies[i];
            int val = solve(i+1,k,child,cookies);
            // cout<<"index: "<<i<<endl;
            // for(auto it: child)
            //     cout<<it<<" ";
            // cout<<endl;
            ans=min(ans,val);
            child[c]-=cookies[i];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int> child(k,0);
        return solve(0,k,child,cookies);
    }
};
