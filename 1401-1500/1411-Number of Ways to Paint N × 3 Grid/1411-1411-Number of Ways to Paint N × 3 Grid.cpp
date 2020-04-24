class Solution {
public:
    int numOfWays(int n) {
        long dp2Color = 6, dp3Color = 6;
        int MOD = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            long temp = dp2Color;
            dp2Color = (dp2Color * 3 + dp3Color * 2) % MOD;
            dp3Color = (temp * 2 + dp3Color * 2) % MOD;
        }

        return (dp2Color + dp3Color) % MOD;
    }
};
