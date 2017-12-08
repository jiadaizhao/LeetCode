class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size();
        if (m == 0) {
            return 0;
        }
        
        int n = M[0].size();
        int maxLen = 0;
        vector<int> cols(n);
        vector<int> diag(m + n - 1);
        vector<int> anti(m + n - 1);
        for (int i = 0; i < m; ++i) {
            int rows = 0;
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) {
                    ++rows;
                    ++cols[j];
                    ++diag[i - j + n - 1];
                    ++anti[i + j];
                    maxLen = max({maxLen, rows, cols[j], diag[i - j + n - 1], anti[i + j]});
                }
                else {
                    rows = 0;
                    cols[j] = 0;
                    diag[i - j + n - 1] = 0;
                    anti[i + j] = 0;
                }                
            }
        }
        
        return maxLen;        
    }
};
