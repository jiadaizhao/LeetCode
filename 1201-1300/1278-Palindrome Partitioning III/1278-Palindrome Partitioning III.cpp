class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n));
        for (int j = 1; j < n; ++j) {
            for (int i = j - 1; i >= 0; --i) {
                cost[i][j] = (s[i] == s[j] ? 0 : 1) + cost[i + 1][j - 1];
            }
        }
        
        vector<int> dp(n);
        for (int j = 1; j < n; ++j) {
            dp[j] = cost[0][j];
        }
        
        for (int l = 2; l <= k; ++l) {
            vector<int> temp(n);
            for (int j = l - 1; j < n; ++j) {
                temp[j] = j + 1;
                for (int i = 0; i < j; ++i) {
                    temp[j] = min(temp[j], dp[i] + cost[i + 1][j]);
                }
            }
            dp = move(temp);
        }
        
        return dp[n - 1];
    }
};
