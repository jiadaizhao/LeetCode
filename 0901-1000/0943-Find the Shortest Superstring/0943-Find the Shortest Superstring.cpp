class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int N = A.size();
        vector<vector<int>> tails(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i != j) {
                    for (int k = 0; k <= A[i].size(); ++k) {
                        if (A[j].substr(0, A[i].size() - k) == A[i].substr(k)) {
                            tails[i][j] = A[j].size() + k - A[i].size();
                            break;
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> dp(1 << N, vector<int>(N, INT_MAX)), parent(1 << N, vector<int>(N, -1));
        int minLen = INT_MAX, last = -1;
        for (int mask = 1; mask < (1 << N); ++mask) {
            for (int bit = 0; bit < N; ++bit) {
                if (mask & (1 << bit)) {
                    int prev = mask - (1 << bit);
                    if (prev == 0) {
                        dp[mask][bit] = A[bit].size();
                    }
                    for (int k = 0; k < N; ++k) {
                        if (prev & (1 << k)) {
                            if (dp[prev][k] != INT_MAX) {
                                int val = dp[prev][k] + tails[k][bit];
                                if (val < dp[mask][bit]) {
                                    dp[mask][bit] = val;
                                    parent[mask][bit] = k;
                                }
                            }
                        }
                    }
                }
                
                if (mask == (1 << N) - 1 && dp[mask][bit] < minLen) {
                    minLen = dp[mask][bit];
                    last = bit;
                }
            }
        }
        
        int curr = (1 << N) - 1;
        stack<int> St;
        while (curr) {
            St.push(last);
            int temp = curr;
            curr -= (1 << last);
            last = parent[temp][last];
        }
        
        int first = St.top();
        string result = A[first];
        St.pop();
        while (!St.empty()) {
            int second = St.top();
            St.pop();
            result += A[second].substr(A[second].size() - tails[first][second]);
            first = second;
        }
        
        return result;
    }
};
