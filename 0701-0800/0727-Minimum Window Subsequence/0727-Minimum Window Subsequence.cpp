class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        if (m < n) {
            return "";
        }
        vector<vector<int>> start(1 + m, vector<int>(1 + n, -1));
        int minLen = m + 1, minStart = -1;
        
        for (int i = 0; i <= m; ++i) {
            start[i][0] = i;
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= min(i, n); ++j) {
                if (S[i - 1] == T[j - 1]) {
                    start[i][j] = start[i - 1][j - 1];
                }
                else {
                    start[i][j] = start[i - 1][j];
                }
            }
            
            if (start[i][n] != -1 && i - start[i][n] < minLen) {
                minStart = start[i][n];
                minLen = i - start[i][n];
            }
        }        
        
        return minStart != -1 ? S.substr(minStart, minLen) : "";
    }
};

// Optimize space
class Solution2 {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        if (m < n) {
            return "";
        }
        vector<int> start(1 + n, -1);
        int minLen = m + 1, minStart = -1;        
        start[0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = min(i, n); j >= 1; --j) {
                if (S[i - 1] == T[j - 1]) {
                    start[j] = start[j - 1];
                }
            }
            start[0] = i;
            if (start[n] != -1 && i - start[n] < minLen) {
                minStart = start[n];
                minLen = i - start[n];
            }
        }        
        
        return minStart != -1 ? S.substr(minStart, minLen) : "";
    }
};