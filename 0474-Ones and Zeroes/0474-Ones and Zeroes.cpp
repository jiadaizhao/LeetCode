class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(1 + m, vector<int>(1 + n));
        for (int i = 0; i < strs.size(); ++i) {
            int count0 = 0, count1 = 0;
            for (char c : strs[i]) {
                if (c == '0') {
                    ++count0;
                }
                else {
                    ++count1;
                }
            }
            for (int j = m; j >= count0; --j) {
                for (int k = n; k >= count1; --k) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - count0][k - count1]);
                }
            }
        }
        
        return dp[m][n];
    }
};
