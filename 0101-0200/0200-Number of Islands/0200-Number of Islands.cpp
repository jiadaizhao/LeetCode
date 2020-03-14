class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }        
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int count = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++count;
                    queue<pair<int, int>> Q;
                    Q.emplace(i, j);
                    visited[i][j] = true;
                    while (!Q.empty()) {
                        int r = Q.front().first;
                        int c = Q.front().second;
                        Q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1' && !visited[nr][nc]) {
                                Q.emplace(nr, nc);
                                visited[nr][nc] = true;
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};
