class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> memo(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
        return dp(n, k, row, column, memo);
    }
    
    double dp(int n, int k, int row, int column, vector<vector<vector<double>>>& memo) {
        if (k == 0) {
            return 1.0;
        }
        if (memo[k][row][column] != 0) {
            return memo[k][row][column];
        }
        
        double sum_prob = 0;
        vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        for (auto move : moves) {
            int nr = row + move.first;
            int nc = column + move.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                sum_prob += dp(n, k - 1, nr, nc, memo);
            }
        }
        
        memo[k][row][column] = sum_prob / 8;
        return sum_prob / 8;
    }
};
