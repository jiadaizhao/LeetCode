class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) {
            return n;
        }

        int dp0 = 0, dp1 = 1, dp2 = 1;
        for (int i = 3; i <= n; ++i) {
            int dp3 = dp0 + dp1 + dp2;
            dp0 = dp1;
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp2;
    }
};
