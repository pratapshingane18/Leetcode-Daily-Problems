class Solution {
public:
    vector<vector<int>>res;
  
    void solve2(int num,int tot,int k,vector<int>&ans){
      if(ans.size()==k){
      res.push_back(ans);
      return;
      }
      for(int i=num;i<=tot;i++){
          ans.push_back(i);
          solve2(i+1,tot,k,ans);
          ans.pop_back();
      }
      
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        solve2(1,n,k,ans);
        return res;
    }
};
