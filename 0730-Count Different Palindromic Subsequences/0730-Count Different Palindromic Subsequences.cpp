class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        int MOD = 1000000007;
        auto dp_ptr = new vector<vector<vector<int>>>(4, vector<vector<int>>(n, vector<int>(n)));
        auto& dp = *dp_ptr;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < 4; ++k) {
                if (S[i] == 'a' + k) {
                    dp[k][i][i] = 1;
                }
            }
        }
        
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                int j = i + l - 1;
                for (int k = 0; k < 4; ++k) {
                    char c = 'a' + k;
                    if (S[i] != c) {
                        dp[k][i][j] = dp[k][i + 1][j];
                    }
                    else if (S[j] != c) {
                        dp[k][i][j] = dp[k][i][j - 1];
                    }
                    else {
                        dp[k][i][j] = 2;
                        if (l != 2) {
                            for (int m = 0; m < 4; ++m) {
                                dp[k][i][j] = (dp[k][i][j] + dp[m][i + 1][j - 1]) % MOD;
                            }
                        }
                    }
                }
            }
        }
        
        int count = 0;
        for (int k = 0; k < 4; ++k) {
            count = (count + dp[k][0][n - 1]) % MOD;
        }
        
        return count;
    }
};

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        prev = vector<vector<int>>(n, vector<int>(4, -1));
        next = vector<vector<int>>(n, vector<int>(4, -1));
        dp = vector<vector<int>>(n, vector<int>(n));
        vector<int> last(4, -1);
        for (int i = 0; i < n; ++i) {
            last[S[i] - 'a'] = i;
            for (int j = 0; j < 4; ++j) {
                prev[i][j] = last[j];
            }
        }
        fill(last.begin(), last.end(), -1);
        for (int i = n - 1; i >= 0; --i) {
            last[S[i] - 'a'] = i;
            for (int j = 0; j < 4; ++j) {
                next[i][j] = last[j];
            }
        }
        
        return dfs(S, 0, n - 1);
    }
    
private:
    vector<vector<int>> prev, next, dp;
    int MOD = 1000000007;
    int dfs(string S, int start, int end) {
        if (start > end) {
            return 0;
        }
        
        if (dp[start][end]) {
            return dp[start][end];
        }
        
        int count = 0;
        for (int k = 0; k < 4; ++k) {
            int i = next[start][k];
            int j = prev[end][k];
            
            if (i == -1 || i > j) {
                continue;
            }
                        
            if (i == j) {
                ++count;
            }
            else {
                count += 2;
                count = (count + dfs(S, i + 1, j - 1)) % MOD;
            }                      
        }
        
        return dp[start][end] = count;
    }
};
