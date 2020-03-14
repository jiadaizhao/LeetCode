class Solution {
public:
    int countOrders(int n) {
        int MOD = 1e9 + 7;
        long result = 1;
        for (int i = 2; i <= n; ++i) {
            result = result * (i * 2 - 1) * i % MOD;
        }
        
        return result;
    }
};
