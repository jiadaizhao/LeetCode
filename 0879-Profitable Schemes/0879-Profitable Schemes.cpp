class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<long long>> dp(1 + G, vector<long long>(1 + P));
        int MOD = 1e9 + 7;
        dp[0][0] = 1;
        
        for (int i = 0; i < group.size(); ++i) {
            for (int g = G; g >= group[i]; --g) {
                for (int p = P; p >= 0; --p) {
                    dp[g][p] = (dp[g][p] + dp[g - group[i]][max(p - profit[i], 0)]) % MOD;
                }
            }
        }
        
        long long sum = 0;
        for (int g = 0; g <= G; ++g) {
            sum = (sum + dp[g][P]) % MOD;
        }
        
        return sum;        
    }
};