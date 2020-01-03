class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> visitedTimes(m, vector<int>(n));
        vector<vector<int>> distance(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++count;
                    bfs(grid, i, j, visitedTimes, distance);
                }
            }
        }
        
        int minDist = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visitedTimes[i][j] == count && (minDist == -1 || distance[i][j] < minDist)) {
                    minDist = distance[i][j];
                }
            }
        }
        return minDist;
    }
    
private:
    void bfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visitedTimes, vector<vector<int>>& distance) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        queue<pair<int, int>> Q;
        vector<vector<bool>> visited(m, vector<bool>(n));
        Q.emplace(row, col);
        visited[row][col] = true;
        int dist = 0;
        while (!Q.empty()) {
            ++dist;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int r = Q.front().first;
                int c = Q.front().second;
                Q.pop();
                for (int k = 0; k < dr.size(); ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && !visited[nr][nc]) {
                        Q.emplace(nr, nc);
                        visited[nr][nc] = true;
                        ++visitedTimes[nr][nc];
                        distance[nr][nc] += dist;
                    }
                }
            }   
        }
    }
};


class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int empty = 0, minDist = -1;
        vector<vector<int>> distance(m, vector<int>(n));
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    minDist = -1;
                    queue<pair<int, int>> Q;
                    Q.emplace(i, j);
                    int dist = 0;
                    while (!Q.empty()) {
                        ++dist;
                        int qs = Q.size();
                        for (int qi = 0; qi < qs; ++qi) {
                            int r = Q.front().first;
                            int c = Q.front().second;
                            Q.pop();
                            for (int k = 0; k < dr.size(); ++k) {
                                int nr = r + dr[k];
                                int nc = c + dc[k];
                                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == empty) {
                                    Q.emplace(nr, nc);
                                    --grid[nr][nc];
                                    distance[nr][nc] += dist;
                                    if (minDist == -1 || distance[nr][nc] < minDist) {
                                        minDist = distance[nr][nc];
                                    }
                                }
                            }
                        }
                    }                   
                    --empty;
                }
            }
        }
        
        return minDist;
    }
};
