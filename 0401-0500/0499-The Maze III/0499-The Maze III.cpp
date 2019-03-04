class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size();
        int n = maze[0].size();
        priority_queue<Cell> Q;
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        Q.emplace(ball[0], ball[1], 0, "");
        distance[ball[0]][ball[1]] = 0;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        vector<char> direction = {'u', 'd', 'l', 'r'};
        while (!Q.empty()) {
            int x = Q.top().row;
            int y = Q.top().col;
            int d = Q.top().dist;
            string dir = Q.top().dir;
            Q.pop();
            if (x == hole[0] && y == hole[1]) {
                return dir;
            }
            
            for (int i = 0; i < dx.size(); ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nd = d + 1;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 0 && !(nx == hole[0] && ny == hole[1])) {
                    nx += dx[i];
                    ny += dy[i];
                    ++nd;
                }
                
                if (!(nx == hole[0] && ny == hole[1])) {
                    nx -= dx[i];
                    ny -= dy[i];
                    --nd;
                }
                
                if (distance[nx][ny] >= nd && !(nx == x && ny == y)) {
                    Q.emplace(nx, ny, nd, dir + direction[i]);
                    distance[nx][ny] = nd;
                }
            }
        }
        
        return "impossible";
    }
    
private:
    struct Cell {
        int row;
        int col;
        int dist;
        string dir;
        Cell(int r, int c, int d, string di): row(r), col(c), dist(d), dir(di){}
        bool operator < (const Cell& c) const {
            if (dist == c.dist) {
                return dir > c.dir;
            }
            return dist > c.dist;
        }
    };
};
