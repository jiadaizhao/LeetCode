class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int maxCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    queue<pair<int, int>> Q;
                    Q.emplace(i, j);
                    grid[i][j] = 0;
                    while (!Q.empty()) {
                        int r = Q.front().first;
                        int c = Q.front().second;
                        ++count;
                        Q.pop();
                        for (int k = 0; k < dx.size(); ++k) {
                            int nr = r + dx[k];
                            int nc = c + dy[k];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                                Q.emplace(nr, nc);
                                grid[nr][nc] = 0;
                            }
                        }
                    }
                    maxCount = max(maxCount, count);
                }
            }
        }
        
        return maxCount;
    }
};
