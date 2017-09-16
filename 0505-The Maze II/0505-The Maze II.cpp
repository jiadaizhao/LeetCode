class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        priority_queue<Cell, vector<Cell>, cmp> Q;
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        Q.emplace(start[0], start[1], 0);
        distance[start[0]][start[1]] = 0;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!Q.empty())
        {
            int x = Q.top().row;
            int y = Q.top().col;
            int d = Q.top().dist;
            Q.pop();
            if (x == destination[0] && y == destination[1])
            {
                return d;
            }
            
            for (int i = 0; i < dx.size(); ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nd = d + 1;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 0)
                {
                    nx += dx[i];
                    ny += dy[i];
                    ++nd;
                }
                
                nx -= dx[i];
                ny -= dy[i];
                --nd;
                
                if (distance[nx][ny] > nd)
                {
                    Q.emplace(nx, ny, nd);
                    distance[nx][ny] = nd;
                }
            }
        }
        
        return -1;
    }
    
private:
    struct Cell {
        int row;
        int col;
        int dist;
        Cell(int r, int c, int d): row(r), col(c), dist(d){}
    };
    
    struct cmp {
        bool operator() (Cell& c1, Cell& c2) {
            return c1.dist > c2.dist;
        }
    };
};
