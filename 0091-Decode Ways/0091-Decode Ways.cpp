class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        
        vector<int> dp(1 + n);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] != '0')
            {
                dp[i] += dp[i - 1];
            }
            
            if (i >= 2 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6')))
            {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};

// Optimize space to O(1)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        
        int dp0 = 1, dp1 = 0, dp2 = 0;
        if (s[0] != '0')
        {
            dp1 = 1;
        }
        if (n == 1)
        {
            return dp1;
        }
        for (int i = 2; i <= n; ++i)
        {
            dp2 = 0;
            if (s[i - 1] != '0')
            {
                dp2 += dp1;
            }
            
            if (i >= 2 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6')))
            {
                dp2 += dp0;
            }
            dp0 = dp1;
            dp1 = dp2;
        }
        
        return dp2;
    }
};
