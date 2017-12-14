class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(1 + m, vector<int>(1 + n));
        
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                }
                else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        
        return dp[m][n];
    }
};

// Space O(n)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> dp(1 + n);
        for (int j = 0; j <= n; ++j) {
            dp[j] = j;
        }
        
        for (int i = 1; i <= m; ++i) {
            vector<int> temp(1 + n);
            temp[0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    temp[j] = dp[j - 1];
                }
                else {
                    temp[j] = 1 + min(temp[j - 1], dp[j]);
                }
            }
            dp = temp;
        }
        
        return dp[n];
    }
};
