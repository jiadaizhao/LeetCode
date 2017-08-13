class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
        {
            return 1;
        }
        
        int dp0 = 1, dp1 = 1;
        int dp2;
        for (int i = 2; i <= n; ++i)
        {
            dp2 = dp0 + dp1;
            dp0 = dp1;
            dp1 = dp2;
        }
        
        return dp2;
    }
};
