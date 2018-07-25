class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size(), maxLen = 0;
        unordered_map<long long, int> table;
        for (int i = 0; i < n; ++i) {
            table[A[i]] = i;
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 2));
        
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                long long next = A[i] + A[j];
                if (table.find(next) != table.end()) {
                    int index = table[next];
                    if (1 + dp[i][j] > dp[j][index]) {
                        dp[j][index] = 1 + dp[i][j];
                        maxLen = max(maxLen, dp[j][index]);
                    }
                }
            }
        }

        return maxLen;
    }
};
