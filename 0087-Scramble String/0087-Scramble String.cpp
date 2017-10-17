class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        
        if (s1 == s2)
        {
            return true;
        }
        if (s1.size() != s2.size())
        {
            return false;
        }
        vector<int> count(26);
        for (char c : s1)
        {
            ++count[c - 'a'];
        }
        
        for (char c : s2)
        {
            if (--count[c - 'a'] < 0)
            {
                return false;
            }
        }
        
        for (int k = 1; k < n; ++k)
        {
            if (isScramble(s1.substr(0, k), s2.substr(0, k)) && isScramble(s1.substr(k), s2.substr(k)))
            {
                return true;
            }
            
            if (isScramble(s1.substr(0, k), s2.substr(n - k)) && isScramble(s1.substr(k), s2.substr(0, n - k)))
            {
                return true;
            }
        }
        
        return false;
    }
};

// Using DP
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n == 0)
        {
            return true;
        }
        
        vector<vector<vector<bool>>> dp(1 + n, vector<vector<bool>>(n, vector<bool>(n)));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        for (int l = 2; l <= n; ++l)
        {
            for (int i = 0; i < n - l + 1; ++i)
            {
                for (int j = 0; j < n - l + 1; ++j)
                {
                    for (int k = 1; k < l && !dp[l][i][j]; ++k)
                    {
                        dp[l][i][j] = dp[k][i][j] && dp[l - k][i + k][j + k] || dp[k][i][j + l - k] && dp[l - k][i + k][j];
                    }
                }
            }
        }
        
        return dp[n][0][0];
    }
};
