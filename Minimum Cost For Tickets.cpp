class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //dp[i][j] where j can be 0 , 1 , 2 , 3

        vector<vector<int>> dp(366,vector<int>(4,INT_MAX)) ;

        int n = days.size() ;

        dp[days[0]][0] = INT_MAX ;
        dp[days[0]][1] = costs[0] , dp[days[0]][2] = costs[1] , dp[days[0]][3] = costs[2] ;

        for(int i = 1 ; i < n ; i++){

            int mini = min(dp[days[i-1]][1],min(dp[days[i-1]][2],dp[days[i-1]][3])) ;

            if(dp[days[i-1]][0] != INT_MAX)
            {
                dp[days[i]][1] = min(dp[days[i-1]][0],mini) + costs[0] ;
                dp[days[i]][2] = min(dp[days[i-1]][0],mini) + costs[1] ;
                dp[days[i]][3] = min(dp[days[i-1]][0],mini) + costs[2] ;
            }
            else{
                dp[days[i]][1] = mini + costs[0] ;
                dp[days[i]][2] = mini + costs[1] ;
                dp[days[i]][3] = mini + costs[2] ;
            }

            for(int j = 0 ; j < i ; j++){
                if(days[j] + 7 > days[i]){
                    dp[days[i]][0] = min(dp[days[i]][0],dp[days[j]][2]) ;
                }
                if(days[j] + 30 > days[i]){
                    dp[days[i]][0] = min(dp[days[i]][0],dp[days[j]][3]) ;
                }
            }
        }

        return 
        min(dp[days[n-1]][0],min(dp[days[n-1]][1],min(dp[days[n-1]][2],dp[days[n-1]][3]))) ;
    }
};
