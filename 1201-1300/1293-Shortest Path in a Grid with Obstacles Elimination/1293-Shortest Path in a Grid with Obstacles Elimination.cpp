class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        queue<tuple<int, int, int>> Q;
        Q.emplace(0, 0, k);
        int visited[m][n][1 + k];
        memset(visited, 0, sizeof(visited));
        visited[0][0][k] = 1;
        int step = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!Q.empty()) {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                auto [r, c, e] = Q.front();
                Q.pop();
                if (r == m - 1 && c == n - 1) {
                    return step;
                }
                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == 0 && !visited[nr][nc][e]) {
                            Q.emplace(nr, nc, e);
                            visited[nr][nc][e] = 1;
                        }
                        else if (grid[nr][nc] == 1 && e > 0 && !visited[nr][nc][e - 1]) {
                            Q.emplace(nr, nc, e - 1);
                            visited[nr][nc][e - 1] = 1;
                        }
                    }
                }
            }
            ++step;
        }
        
        return -1;
    }
};
