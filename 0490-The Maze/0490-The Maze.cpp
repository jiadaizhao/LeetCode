class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> Q;
        vector<vector<bool>> visited(m, vector<bool>(n));
        Q.emplace(start[0], start[1]);
        visited[start[0]][start[1]] = true;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!Q.empty())
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            if (x == destination[0] && y == destination[1])
            {
                return true;
            }
            
            for (int i = 0; i < dx.size(); ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 0)
                {
                    nx += dx[i];
                    ny += dy[i];
                }
                
                nx -= dx[i];
                ny -= dy[i];
                if (visited[nx][ny])
                {
                    continue;
                }
                Q.emplace(nx, ny);
                visited[nx][ny] = true;
            }
        }
        
        return false;
    }
};
