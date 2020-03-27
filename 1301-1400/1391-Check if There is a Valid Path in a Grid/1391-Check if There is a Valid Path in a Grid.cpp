class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[0][0] = true;
        vector<vector<pair<int, int>>> direction = { {},
            { { 0, -1 }, { 0, 1 } },
            { { -1, 0 }, { 1, 0 } },
            { { 0, -1 }, { 1, 0 } },
            { { 0, 1 }, { 1, 0 } },
            { { -1, 0 }, { 0, -1 } },
            { { -1, 0}, { 0, 1 } },
        };
        while (!Q.empty()) {
            int r = Q.front().first;
            int c = Q.front().second;
            if (r == m - 1 && c == n - 1) {
                return true;
            }
            Q.pop();
            for (auto&[dr, dc] : direction[grid[r][c]]) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    for (auto&[bdr, bdc] : direction[grid[nr][nc]]) {
                        if (nr + bdr == r && nc + bdc == c) {
                            Q.push({ nr, nc });
                            visited[nr][nc] = true;
                            break;
                        }
                    }
                }
            }
        }

        return false;
    }
};
