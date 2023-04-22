class Solution {
public:

bool checkpal(string &s, int left, int right){
    //after half string is check and if no false case if found then its ultimately palinfrome

    if(left >= right){
        return true;
    }

    // Base case
    if(s[left] != s[right]){
        return false;
    }

    // recurrsivly checking
    return checkpal(s,left+1,right-1);

    
}



    int minInsertions(string s) {
          int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
// int n = s.size();
//        if(checkpal(s,0,n-1)){
//            return 0;
//        }

//        else{
//            return 1;
//        }
        
    }
};
