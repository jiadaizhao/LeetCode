class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();       
        vector<vector<bool>> visited(m, vector<bool>(n));
        addQ(grid, visited, 0, 0);
        int step = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!Q.empty()) {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int r = Q.front().first;
                int c = Q.front().second;
                if (r == m - 1 && c == n - 1) {
                    return step;
                }
                Q.pop();
                for (int j = 0 ; j < 4; ++j) {
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        addQ(grid, visited, nr, nc);
                    }
                }
            }
            ++step;
        }

        return -1;
    }

private:
    queue<pair<int, int>> Q;
    void addQ(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        int m = visited.size(), n = visited[0].size();
        while (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {
            Q.emplace(r, c);
            visited[r][c] = true;
            if (grid[r][c] == 1) {
                ++c;
            }
            else if (grid[r][c] == 2) {
                --c;
            }
            else if (grid[r][c] == 3) {
                ++r;
            }
            else {
                --r;
            }
        }
    }
};
