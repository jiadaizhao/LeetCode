// BFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();        
        int n = matrix[0].size();
        queue<pair<int, int>> Q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    Q.emplace(i, j);
                    dist[i][j] = 0;
                }
            }
        }
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!Q.empty()) {
            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int nrow = row + dr[k];
                int ncol = col + dc[k];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && dist[nrow][ncol] > dist[row][col] + 1) {
                    dist[nrow][ncol] = dist[row][col] + 1;
                    Q.emplace(nrow, ncol);
                }
            }
        }
        
        return dist;
    }
};

// DP
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();        
        int n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX - 10000));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0) {
                    if (j > 0) {
                        dist[i][j] = min(dist[i][j], 1 + dist[i][j - 1]);
                    } 
                    if (i > 0) {
                        dist[i][j] = min(dist[i][j], 1 + dist[i - 1][j]);
                    }
                }
                else {
                    dist[i][j] = 0;
                }
            }
        }
                
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] != 0) {
                    if (j < n - 1) {
                        dist[i][j] = min(dist[i][j], 1 + dist[i][j + 1]);
                    } 
                    if (i < m - 1) {
                        dist[i][j] = min(dist[i][j], 1 + dist[i + 1][j]);
                    }
                }
            }
        }
        
        return dist;
    }
};
