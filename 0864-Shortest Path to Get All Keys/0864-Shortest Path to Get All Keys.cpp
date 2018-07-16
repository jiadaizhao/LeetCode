class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int numKey = 0, startRow = -1, startCol = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    startRow = i;
                    startCol = j;
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    ++numKey;
                }
            }
        }
        
        int target = (1 << numKey) - 1;
        queue<Node> Q;
        unordered_set<string> visited;
        visited.insert("0 " + to_string(startRow) + " " + to_string(startCol));
        Q.emplace(0, startRow, startCol);
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1 , 1};
        int step = 0;
        while (!Q.empty()) {
            ++step;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int state = Q.front().state;
                int row = Q.front().row;
                int col = Q.front().col;
                Q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];
                    int nextState = state;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        char c = grid[nr][nc];
                        if (c == '#' || (c >= 'A' && c <= 'F' && (state & (1 << (c - 'A'))) == 0)) {
                            continue;
                        }
                        if (c >= 'a' && c <= 'f') {
                            nextState |= (1 << (grid[nr][nc] - 'a'));
                            if (nextState == target) {
                                return step;
                            }
                        }
                        
                        string path = to_string(nextState) + " " + to_string(nr) + " " + to_string(nc);
                        if (!visited.count(path)) {
                            visited.insert(path);
                            Q.emplace(nextState, nr, nc);
                        }
                    }
                }
            }            
        }
        
        return -1;
    }
    
private:
    struct Node {
        int state;
        int row;
        int col;
        Node(int s, int r, int c): state(s), row(r), col(c){}
    };
};
