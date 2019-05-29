class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> Q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    ++fresh;
                }
                else if (grid[i][j] == 2) {
                    Q.emplace(i, j);
                }
            }
        }
        
        int time = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (fresh && !Q.empty()) {
            int qs = Q.size();
            ++time;
            for (int i = 0; i < qs; ++i) {
                int row = Q.front().first;
                int col = Q.front().second;
                Q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];
                    if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        --fresh;
                        Q.emplace(nr, nc);
                    }
                }
            }
        }
        
        return fresh == 0 ? time : -1;
    }
};
