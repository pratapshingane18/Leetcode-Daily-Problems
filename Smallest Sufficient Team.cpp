#define ll long long int
class Solution {
public:
    unordered_map<string, ll> dp;
    ll f(ll i,vector<ll> &hash,ll mask,ll n){
        if(mask==(1<<n)-1) return 0;
        if(i>=hash.size()){
            return INT_MAX;
        }
        string key=to_string(i)+" "+to_string(mask);
        if(dp.count(key)) return dp[key];
        ll ans=INT_MAX;
        ll pick=f(i+1,hash,mask|hash[i],n);
        ll nonpick=f(i+1,hash,mask,n);
        if (__builtin_popcountll(pick)<__builtin_popcountll(nonpick)) ans=pick|(1LL<<i);
        else ans=nonpick;
        return dp[key]=ans;
    }
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& peo) {
        ll n=req.size();
        ll m=peo.size();
        map<string,ll> mp;
        for(int i=0;i<n;i++){
            mp[req[i]]=(1<<i);
        }
        vector<ll> hash;
        for(int i=0;i<m;i++){
            int mask=0;
            for(auto x:peo[i]){
                mask=mask|mp[x];
            }
            hash.push_back(mask);
        }
        ll cnt=f(0,hash,0,n);
        vector<int> ans;
        int idx=0;
        while(cnt>0) {
            ll pick=cnt&1;
            if (pick==1) {
                ans.push_back(idx);
            }
            idx++;
            cnt=cnt/2;
        }
        return ans;
    }
};
