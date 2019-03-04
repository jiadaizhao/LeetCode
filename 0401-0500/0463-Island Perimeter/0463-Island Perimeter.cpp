class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        
        int n = grid[0].size();
        int count = 0;
        int neighbor = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++count;
                    if (i > 0 && grid[i - 1][j]) {
                        ++neighbor;
                    }
                    
                    if (j > 0 && grid[i][j - 1]) {
                        ++neighbor;
                    }
                }
            }
        }
        
        return count * 4 - neighbor * 2;
    }
};

// DFS to cover usual case
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        
        int n = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, perimeter);
                    return perimeter;
                }
                
            }
        }
        return perimeter;
    }
    
private:
    unordered_set<int> visited;
    void dfs(vector<vector<int>>& grid, int row, int col, int& perimeter) {
        int m = grid.size();        
        int n = grid[0].size();
        if (visited.count(row * n + col)) {
            return;
        }
        
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        visited.insert(row * n + col);
        for (int k = 0; k < dr.size(); ++k) {
            int nr = row + dr[k];
            int nc = col + dc[k];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == 0) {
                ++perimeter;
            }
            else {
                dfs(grid, nr, nc, perimeter);
            }
        }
    }
};
