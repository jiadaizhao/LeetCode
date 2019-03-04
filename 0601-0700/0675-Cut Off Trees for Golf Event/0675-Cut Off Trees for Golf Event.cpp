class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        if (m == 0) {
            return 0;
        }
        
        int n = forest[0].size();
        vector<Node> trees;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(i, j, forest[i][j]);
                }
            }
        }
        
        sort(trees.begin(), trees.end());
        
        int count = 0;
        int startx = 0, starty = 0;
        for (int i = 0; i < trees.size(); ++i) {
            if (!bfs(startx, starty, trees[i], forest, count)) {
                return -1;
            }
            startx = trees[i].row;
            starty = trees[i].col;
        }
        
        return count;
    }
    
private:
    class Node {
    public:
        int row;
        int col;
        int val;
        Node(int r, int c, int v): row(r), col(c), val(v){}
        bool operator < (const Node node) const {
            return val < node.val;
        }
    };
    
    bool bfs(int startx, int starty, Node& node, vector<vector<int>>& forest, int& count) {
        int m = forest.size();
        int n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int targetx = node.row;
        int targety = node.col;
        queue<Node> Q;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        Q.emplace(startx, starty, 0);
        visited[startx][starty] = true;
        while (!Q.empty()) {
            int x = Q.front().row;
            int y = Q.front().col;
            int d = Q.front().val;
            if (x == targetx && y == targety) {
                count += d;
                forest[x][y] = 1;
                return true;
            }
            Q.pop();
            for (int k = 0; k < dx.size(); ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && forest[nx][ny] != 0) {
                    Q.emplace(nx, ny, d + 1);
                    visited[nx][ny] = true;
                }
            }
        }
        
        return false;
    }
};

// A* search
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        if (m == 0) {
            return 0;
        }
        
        int n = forest[0].size();
        vector<Node> trees;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(i, j, forest[i][j]);
                }
            }
        }
        
        sort(trees.begin(), trees.end());
        
        int count = 0;
        int startr = 0, startc = 0;
        for (int i = 0; i < trees.size(); ++i) {
            if (!search(startr, startc, trees[i], forest, count)) {
                return -1;
            }
            startr = trees[i].row;
            startc = trees[i].col;
        }
        
        return count;
    }
    
private:
    class Node {
    public:
        int row;
        int col;
        int val;
        Node(int r, int c, int v): row(r), col(c), val(v){}
        bool operator < (const Node node) const {
            return val < node.val;
        }
    };
    
    class Weight {
    public:
        int row;
        int col;
        int f;
        int g;
        Weight(int r, int c, int ff, int gg): row(r), col(c), f(ff), g(gg){}
        bool operator < (const Weight w) const {
            if (f == w.f) {
                return g > w.g;
            }
            return f > w.f;
        }
    };
    
    bool search(int startr, int startc, Node& node, vector<vector<int>>& forest, int& count) {
        int m = forest.size();
        int n = forest[0].size();
        unordered_map<int, int> costs;
        priority_queue<Weight> pq;
        pq.emplace(startr, startc, 0, 0);
        costs[startr * n + startc] = 0;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        int targetr = node.row;
        int targetc = node.col;
        while (!pq.empty()) {
            int r = pq.top().row;
            int c = pq.top().col;
            int f = pq.top().f;
            int g = pq.top().g;
            if (r == targetr && c == targetc) {
                count += g;
                forest[r][c] = 1;
                return true;
            }
            pq.pop();
            for (int k = 0; k < dr.size(); ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && forest[nr][nc] != 0) {
                    int nf = g + 1 + abs(nr - targetr) + abs(nc - targetc);
                    if (!costs.count(nr * n + nc) || nf < costs[nr * n + nc]) {
                        costs[nr * n + nc] = nf;
                        pq.emplace(nr, nc, nf, g + 1);
                    }
                }
            }
        }
        
        return false;
    }
};
