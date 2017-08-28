class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
        {
            return 0;
        }
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n));
        vector<vector<int>> visitedTimes(m, vector<int>(n));
        int count = 0;
        int minDist = -1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++count;
                    bfs(grid, i, j, distance, visitedTimes);
                }
            }
        }
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (visitedTimes[i][j] == count)
                {
                    if (minDist == -1 || distance[i][j] < minDist)
                    {
                        minDist = distance[i][j];
                    }
                }
            }
        }
        
        return minDist;
    }
    
private:
    void bfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& distance, vector<vector<int>>& visitedTimes)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> Q;
        Q.push({x, y});
        visited[x][y] = true;
        int dist = 0;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!Q.empty())
        {
            ++dist;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i)
            {
                int xx = Q.front().first;
                int yy = Q.front().second;
                Q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int nx = xx + dx[k];
                    int ny = yy + dy[k];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 0)
                    {
                        Q.push({nx, ny});
                        visited[nx][ny] = true;
                        distance[nx][ny] += dist;
                        ++visitedTimes[nx][ny];
                    }
                }
            }
        }
    }
};
