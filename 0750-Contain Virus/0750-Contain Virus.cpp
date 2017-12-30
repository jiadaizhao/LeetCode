class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        dr = {-1, 1, 0, 0};
        dc = {0, 0, -1, 1};
        int m = grid.size();
        int n = grid[0].size();
        int wall = 0;
        while (true) {
            vector<vector<int>> regions;
            vector<unordered_set<int>> frontiers;
            vector<int> perimeters;
            unordered_set<int> visited;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1 && visited.find(i * n + j) == visited.end()) {
                        regions.push_back(vector<int>());
                        frontiers.push_back(unordered_set<int>());
                        perimeters.push_back(0);
                        dfs(grid, i, j, regions, frontiers, perimeters, visited);
                    }
                }
            }
            
            if (regions.size() == 0) {
                break;
            }

            int maxP = 0;
            for (int i = 1; i < frontiers.size(); ++i) {
                if (frontiers[i].size() > frontiers[maxP].size()) {
                    maxP = i;
                }
            }

            wall += perimeters[maxP];
            for (int i = 0; i < regions.size(); ++i) {
                for (int j : regions[i]) {
                    int r = j / n;
                    int c = j % n;
                    if (i == maxP) {
                        grid[r][c] = -1;
                    }
                    else {
                        for (int k = 0; k < dr.size(); ++k) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                                grid[nr][nc] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        return wall;
    }
    
private:
    vector<int> dr, dc;
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& regions, vector<unordered_set<int>>& frontiers,
            vector<int>& perimeters, unordered_set<int>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        if (visited.find(r * n + c) == visited.end()) {
            visited.insert(r * n + c);
            regions.back().push_back(r * n + c);            
            for (int k = 0; k < dr.size(); ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && visited.find(nr * n + nc) == visited.end()) {
                    if (grid[nr][nc] == 1) {
                        dfs(grid, nr, nc, regions, frontiers, perimeters, visited);
                    }
                    else if (grid[nr][nc] == 0) {
                        frontiers.back().insert(nr * n + nc);
                        ++perimeters.back();
                    }
                }
            }
        }
    }
};
