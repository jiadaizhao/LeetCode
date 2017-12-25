class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        
        int n = grid[0].size();
        set<vector<int>> table;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    vector<int> path;
                    queue<pair<int, int>> Q;
                    Q.emplace(i, j);
                    grid[i][j] = 0;
                    while (!Q.empty()) {
                        auto p = Q.front();
                        int r = p.first;
                        int c = p.second;
                        Q.pop();
                        for (int k = 0; k < dx.size(); ++k) {
                            int nr = r + dx[k];
                            int nc = c + dy[k];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                                Q.emplace(nr, nc);
                                grid[nr][nc] = 0;
                                path.push_back(k + 1);                                
                            }
                        }
                        path.push_back(0);
                    }
                    table.insert(path);
                }
            }
        }
        
        return table.size();
    }
};
