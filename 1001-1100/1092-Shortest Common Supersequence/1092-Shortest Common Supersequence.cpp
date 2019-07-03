class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(1 + m, vector<int>(1 + n));
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        string result = string(dp[m][n], ' ');
        int i = m - 1, j = n - 1, k = result.size() - 1;
        while (i >= 0 && j >= 0) {
            if (str1[i] == str2[j]) {
                result[k--] = str1[i--];
                --j;
            }
            else if (dp[i][j + 1] < dp[i + 1][j]) {
                result[k--] = str1[i--];
            }
            else {
                result[k--] = str2[j--];
            }
        }
        
        while (i >= 0) {
            result[k--] = str1[i--];
        }
        
        while (j >= 0) {
            result[k--] = str2[j--];
        }
        
        return result;
    }
};
