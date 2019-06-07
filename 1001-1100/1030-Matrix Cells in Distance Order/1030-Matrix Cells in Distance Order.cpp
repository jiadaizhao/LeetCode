class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        vector<vector<bool>> visited(R, vector<bool>(C));
        queue<pair<int, int>> Q;
        Q.emplace(r0, c0);
        visited[r0][c0] = true;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!Q.empty()) {
            int row = Q.front().first;
            int col = Q.front().second;
            result.push_back({row, col});
            Q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = row + dr[k];
                int nc = col + dc[k];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]) {
                    Q.emplace(nr, nc);
                    visited[nr][nc] = true;
                }
            }
        }
        
        return result;
    }
};
