class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        
        unordered_map<char, vector<int>> table;
        for (int i = 0; i < n; ++i) {
            table[ring[i]].push_back(i);
        }
        
        int m = key.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int j = 0; j < n; ++j) {
            if (key[0] == ring[j]) {
                dp[0][j] = min(j, n - j) + 1;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j : table[key[i]]) {
                for (int k : table[key[i - 1]]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        
        int result = INT_MAX;
        for (int j : table[key[m - 1]]) {
            result = min(result, dp[m - 1][j]);
        }
        
        return result;
    }
};
