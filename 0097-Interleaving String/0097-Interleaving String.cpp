class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (s3.size() != m + n)
        {
            return false;
        }
        
        vector<vector<bool>> dp(1 + m, vector<bool>(1 + n));
        
        dp[0][0] = true;
        for (int i = 1; i <= m && dp[i - 1][0]; ++i)
        {
            dp[i][0] = (s1[i - 1] == s3[i - 1]);
        }
        
        for (int j = 1; j <= n && dp[0][j - 1]; ++j)
        {
            dp[0][j] = (s2[j - 1] == s3[j - 1]);
        }
        
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = (s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j] ||
                           (s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1];
            }
        }
        
        return dp[m][n];
    }
};

// Optimize space to O(n)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (s3.size() != m + n)
        {
            return false;
        }
        
        vector<bool> dp(1 + n);
        dp[0] = true;
        for (int j = 1; j <= n && dp[j - 1]; ++j)
        {
            dp[j] = (s2[j - 1] == s3[j - 1]);
        }
        for (int i = 1; i <= m; ++i)
        {
            vector<bool> temp(1 + n);
            temp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n; ++j)
            {
                temp[j] = (s1[i - 1] == s3[i + j - 1]) && dp[j] ||
                           (s2[j - 1] == s3[i + j - 1]) && temp[j - 1];
            }
            dp = temp;
        }
        
        return dp[n];
    }
};
