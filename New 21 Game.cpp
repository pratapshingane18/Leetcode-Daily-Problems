class Solution {
public:
    double new21Game(int n, int k, int w) {
        if (n >= k+w-1) return 1.0;
        vector<double> dp(k+w);
        dp[0] = 1;
        double p = 1/(double)w;

        double cur = 0;
        for (int i = 1; i <= k; i++) {
            if (i-w-1 >= 0) cur -= dp[i-w-1];
            cur += dp[i-1];
            dp[i] = cur * p;
        }
        double ans = dp[k];

        for (int i = k+1; i <= n; i++) {
            if (i-w-1 >= 0) cur -= dp[i-w-1];
            dp[i] = cur * p;
            ans += dp[i];
        }

        return ans;
    }
};
