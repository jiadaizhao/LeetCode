class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for (int j = 0; j < s.size(); ++j) {
            dp[j][j] = 1;
            for (int i = j - 1; i >= 0; --i) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        return dp[0].back() >= s.size() - k;
    }
};
