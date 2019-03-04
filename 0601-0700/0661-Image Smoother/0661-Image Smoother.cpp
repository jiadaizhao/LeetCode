class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<int> dx = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        vector<int> dy = {1, 0, -1, 1, 0, -1, 1, 0, -1};
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                int count = 0;
                for (int k = 0; k < dx.size(); ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        ++count;
                        sum += M[ni][nj];
                    }
                }
                int val = sum / count;
                result[i][j] = val;
            }
        }
        
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<int> dx = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        vector<int> dy = {1, 0, -1, 1, 0, -1, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                int count = 0;
                for (int k = 0; k < dx.size(); ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        ++count;
                        sum += M[ni][nj] & 0xFF;
                    }
                }
                int val = sum / count;
                M[i][j] |= (val << 8);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                M[i][j] >>= 8;
            }
        }
        
        return M;
    }
};
