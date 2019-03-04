class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        
        vector<vector<bool>> dp(n, vector<bool>(n));
        int count = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = j; i >= 0; --i) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ++count;
                }
            }
        }
        
        return count;
    }
};
