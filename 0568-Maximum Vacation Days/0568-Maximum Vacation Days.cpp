class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int N = flights.size();
        int K = days[0].size();
        
        vector<vector<int>> dp(2, vector<int>(N));
        for (int i = K - 1; i >= 0; --i) {
            for (int j = 0; j < N; ++j) {
                dp[i & 1][j] = dp[(i + 1) & 1][j] + days[j][i];
                for (int k = 0; k < N; ++k) {
                    if (flights[j][k]) {
                        dp[i & 1][j] = max(dp[i & 1][j], dp[(i + 1) & 1][k] + days[k][i]);
                    }                    
                }
            }
        }
        
        return dp[0][0];
    }
};
