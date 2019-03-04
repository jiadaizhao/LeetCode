class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) {
            return 0;
        }
        int n = heightMap[0].size();
        priority_queue<Cell> pq;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            pq.emplace(i, 0, heightMap[i][0]);
            visited[i][0] = true;
            if (n > 1) {
                pq.emplace(i, n - 1, heightMap[i][n - 1]);
                visited[i][n - 1] = true;
            }
        }
        
        for (int j = 1; j < n - 1; ++j) {
            pq.emplace(0, j, heightMap[0][j]);
            visited[0][j] = true;
            if (m > 1) {
                pq.emplace(m - 1, j, heightMap[m - 1][j]);
                visited[m - 1][j] = true;
            }
        }
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int sum = 0;
        while (!pq.empty()) {
            Cell cell = pq.top();
            pq.pop();
            int row = cell.row;
            int col = cell.col;
            int val = cell.val;
            for (int k = 0; k < dx.size(); ++k) {
                int nr = row + dx[k];
                int nc = col + dy[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.emplace(nr, nc, max(val, heightMap[nr][nc]));
                    visited[nr][nc] = true;
                    sum += max(val - heightMap[nr][nc], 0);
                }
            }
        }
        
        return sum;
    }
    
private:
    struct Cell {
        int row;
        int col;
        int val;
        Cell(int r, int c, int v): row(r), col(c), val(v) {}
        bool operator < (const Cell& c) const {
            return val > c.val;
        }
    };
};
