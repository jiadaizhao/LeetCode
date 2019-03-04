class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int MOD = 1000000007, n = A.size();
        sort(A.begin(), A.end());
        vector<long long> dp(n, 1);
        unordered_map<int, int> table;
        for (int i = 0; i < n; ++i) {
            table[A[i]] = i;
        }
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0) {
                    int num = A[i] / A[j];
                    if (table.count(num)) {        
                        dp[i] = (dp[i] + dp[j] * dp[table[num]]) % MOD;
                    }                    
                }
            }
            total = (total + dp[i]) % MOD;
        }
        return total;
    }
};
