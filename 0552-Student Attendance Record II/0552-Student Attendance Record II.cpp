class Solution {
public:
    int checkRecord(int n) {
        int dp[1 + n][2][3] = {1, 1, 1, 1, 1, 1};
        int m = 1000000007;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= 1; ++j)
            {
                for (int k = 0; k <= 2; ++k)
                {
                    int val = dp[i - 1][j][2]; // P
                    if (k > 0)
                    {
                        val = (val + dp[i - 1][j][k - 1]) % m; // L
                    }
                    
                    if (j > 0)
                    {
                        val = (val + dp[i - 1][j - 1][2]) % m; // A
                    }                    
                    
                    dp[i][j][k] = val;
                }
            }
        }
        
        return dp[n][1][2];
    }
};

// O(1) space
class Solution {
public:
    int checkRecord(int n) {
        int dp00 = 1, dp01 = 0, dp02 = 0, dp10 = 0, dp11 = 0, dp12 = 0;
        int m = 1000000007;
        for (int i = 1; i <= n; ++i)
        {
            int t00 =  ((long)dp00 + dp01 + dp02) % m;
            int t01 = dp00;
            int t02 = dp01;
            int t10 = ((long)dp00 + dp01 + dp02 + dp10 + dp11 + dp12) % m;
            int t11 = dp10;
            int t12 = dp11;
            
            dp00 = t00;
            dp01 = t01;
            dp02 = t02;
            dp10 = t10;
            dp11 = t11;
            dp12 = t12;
        }
        
        return ((long)dp00 + dp01 + dp02 + dp10 + dp11 + dp12) % m;
    }
};
