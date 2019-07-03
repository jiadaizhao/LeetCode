class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] || grid[m - 1][n - 1]) {
            return -1;
        } 
        queue<pair<int, int>> Q;
        Q.emplace(0, 0);
        grid[0][0] = 1;
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int step = 0;
        while (!Q.empty()) {
            ++step;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int r = Q.front().first;
                int c = Q.front().second;
                if (r == m - 1 && c == n - 1) {
                    return step;
                }
                Q.pop();
                for (int k = 0; k < 8; ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        Q.emplace(nr, nc);
                        grid[nr][nc] = 1;
                    }
                }
            }
        }
        
        return -1;
    }
};
