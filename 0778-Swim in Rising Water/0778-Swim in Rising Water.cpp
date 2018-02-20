class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> visited;
        priority_queue<Node> pq;
        pq.emplace(0, 0, grid[0][0]);
        visited.insert(0);
        int t = 0;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        while (!pq.empty()) {
            int row = pq.top().row;
            int col = pq.top().col;
            int val = pq.top().val;
            pq.pop();
            t = max(t, val);
            if (row == n - 1 && col == n - 1) return t;
            for (int k = 0; k < dr.size(); ++k) {
                int nr = row + dr[k];
                int nc = col + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited.count(nr * n + nc)) {
                    pq.emplace(nr, nc, grid[nr][nc]);
                    visited.insert(nr * n + nc);
                }
            }
        }
        
        return -1;
    }
    
private:
    struct Node {
        int row;
        int col;
        int val;
        Node(int r, int c, int v): row(r), col(c), val(v) {}
        bool operator < (const Node& node) const {
            return val > node.val;
        }
    };
};
