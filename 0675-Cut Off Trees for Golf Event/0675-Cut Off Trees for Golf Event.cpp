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
