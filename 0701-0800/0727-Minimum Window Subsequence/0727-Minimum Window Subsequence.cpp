class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size();
        int n = T.size();
        if (m < n) {
            return "";
        }
        vector<vector<int>> start(1 + m, vector<int>(1 + n, -1));
        int minLen = -1;
        int minStart = -1;
        
        for (int i = 0; i <= m; ++i) {
            start[i][0] = i;
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = min(i, n); j >= 1; --j) {
                if (S[i - 1] == T[j - 1]) {
                    start[i][j] = start[i - 1][j - 1];
                }
                else {
                    start[i][j] = start[i - 1][j];
                }
            }
            
            if (start[i][n] != -1) {
                if (minLen == -1 || i - start[i][n] < minLen) {
                    minStart = start[i][n];
                    minLen = i - start[i][n];
                }
            }
        }        
        
        return minLen != -1 ? S.substr(minStart, minLen) : "";
    }
};

class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size();
        int n = T.size();
        if (m < n) {
            return "";
        }
        vector<int> start(1 + n, -1);
        int minLen = -1;
        int minStart = -1;
        
        start[0] = 0;        
        for (int i = 1; i <= m; ++i) {
            for (int j = min(i, n); j >= 1; --j) {
                if (S[i - 1] == T[j - 1]) {
                    start[j] = start[j - 1];
                }
            }
            start[0] = i;
            
            if (start[n] != -1) {
                if (minLen == -1 || i - start[n] < minLen) {
                    minStart = start[n];
                    minLen = i - start[n];
                }
            }
        }
        
        return minLen != -1 ? S.substr(minStart, minLen) : "";
    }
};
