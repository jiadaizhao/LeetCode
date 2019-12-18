class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<double> dp(1 + target);
        dp[0] = 1;
        for (int i = 0; i < prob.size(); ++i) {
            for (int j = min(target, i + 1); j >= 0; --j) {
                dp[j] = (j > 0 ? dp[j - 1] : 0) * prob[i] + dp[j] * (1 - prob[i]);
            }
        }
        return dp[target];
    }
};
