// BFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
        {
            return matrix;
        }
        
        int n = matrix[0].size();
        queue<Cell> Q;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    Q.emplace(i, j, matrix[i][j]);
                    visited[i][j] = true;
                }
            }
        }
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!Q.empty())
        {
            int row = Q.front().row;
            int col = Q.front().col;
            int val = Q.front().val;
            Q.pop();
            
            for (int k = 0; k < dx.size(); ++k)
            {
                int nrow = row + dx[k];
                int ncol = col + dy[k];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol])
                {
                    matrix[nrow][ncol] = val + 1;
                    Q.emplace(nrow, ncol, matrix[nrow][ncol]);
                    visited[nrow][ncol] = true;
                }
            }
        }
        
        return matrix;
    }
    
private:
    struct Cell {
        int row;
        int col;
        int val;
        Cell(int r, int c, int v): row(r), col(c), val(v) {}
    };
};

// DP
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return matrix;
        }
        
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
