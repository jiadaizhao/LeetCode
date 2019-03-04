class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        int m = matrix.size();
        if (m == 0) {
            return result;
        }
        
        int n = matrix[0].size();
        vector<vector<int>> visitedTimes(m, vector<int>(n));
        
        bfs(matrix, visitedTimes, true);
        bfs(matrix, visitedTimes, false);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visitedTimes[i][j] == 2) {
                    result.emplace_back(i, j);
                }
            }
        }
        
        return result;
    }
    
private:
    struct Cell {
        int x;
        int y;
        int height;
        Cell (int xx, int yy, int hh): x(xx), y(yy), height(hh) {}
    };
    
    void bfs(vector<vector<int>>& matrix, vector<vector<int>>& visitedTimes, bool pac) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<Cell> Q;
        if (pac) {
            for (int i = 0; i < m; ++i) {
                ++visitedTimes[i][0];
                visited[i][0] = true;
                Q.emplace(i, 0, matrix[i][0]);
            }
            
            for (int j = 1; j < n; ++j) {
                ++visitedTimes[0][j];
                visited[0][j] = true;
                Q.emplace(0, j, matrix[0][j]);
            }
        }
        else {
            for (int i = 0; i < m; ++i) {
                ++visitedTimes[i][n - 1];
                visited[i][n - 1] = true;
                Q.emplace(i, n - 1, matrix[i][n - 1]);
            }
            
            for (int j = 0; j < n - 1; ++j) {
                ++visitedTimes[m - 1][j];
                visited[m - 1][j] = true;
                Q.emplace(m - 1, j, matrix[m - 1][j]);
            }
        }
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!Q.empty()) {
            int x = Q.front().x;
            int y = Q.front().y;
            int height = Q.front().height;
            Q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && matrix[nx][ny] >= height) {
                    ++visitedTimes[nx][ny];
                    visited[nx][ny] = true;
                    Q.emplace(nx, ny, matrix[nx][ny]);
                }
            }
        }
    }
};
