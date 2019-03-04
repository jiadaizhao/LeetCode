class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        
        vector<int> dp(n);
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        for (int j = 0; j < n; ++j) {
            dp[j] = j;
            for (int i = j; i >= 0; --i) {
                if (s[i] == s[j] && (j - i < 2 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                    if (i == 0) {
                        dp[j] = 0;
                    }
                    else {
                        dp[j] = min(dp[j], 1 + dp[i - 1]);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};
