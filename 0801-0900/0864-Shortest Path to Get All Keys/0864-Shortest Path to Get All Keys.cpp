// Dijkstra's algorithm
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), numKey = 0;
        unordered_map<char, unordered_map<char, int>> dists;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != '.' && grid[i][j] != '#') {
                    if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                        ++numKey;
                    }
                    dists[grid[i][j]] = bfs(grid, grid[i][j], i, j);
                }
                
            }
        }
        
        int target = (1 << numKey) - 1;
        priority_queue<Cell> pq;
        pq.emplace(0, '@', 0);
        unordered_map<string, int> final_dist;
        while (!pq.empty()) {
            int d = pq.top().d;
            char curr = pq.top().curr;
            int state = pq.top().state;
            pq.pop();
            string s = curr + to_string(state);
            if (final_dist.count(s)) {
                continue;
            }          
            
            final_dist[s] = d;
            if (state == target) {
                return d;
            }
            for (auto& p : dists[curr]) {
                char destination = p.first;
                int d2 = p.second;
                int state2 = state;
                if (islower(destination)) {
                    state2 |= (1 << (destination - 'a'));
                }
                else if (isupper(destination)) {
                    if (!(state & (1 << (destination - 'A'))))
                        continue;
                }
                
                string ds = destination + to_string(state2);
                if (!final_dist.count(ds)) {
                    pq.emplace(d + d2, destination, state2);
                }
            }
        }
        
        return -1;
    }
    
private:
    struct Node {
        int d;
        int row;
        int col;
        Node(int dd, int r, int c): d(dd), row(r), col(c){}
    };
    unordered_map<char, int> bfs(vector<string>& grid, char source, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        queue<Node> Q;
        Q.emplace(0, r, c);
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[r][c] = true;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1 , 1};
        unordered_map<char, int> dist;
        while (!Q.empty()) {
            int d = Q.front().d;
            int row = Q.front().row;
            int col = Q.front().col;
            Q.pop();
            if (grid[row][col] != source and grid[row][col] != '.') {
                dist[grid[row][col]] = d;
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                int nr = row + dr[k];
                int nc = col + dc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != '#' && !visited[nr][nc]) {
                    Q.emplace(d + 1, nr, nc);
                    visited[nr][nc] = true;
                }
            }
        }
        return dist;
    }
    
    struct Cell {
        int d;
        char curr;
        int state;
        Cell(int dd, char c, int s): d(dd), curr(c), state(s){}
        bool operator < (const Cell & c) const {
            if (d == c.d) {
                return curr < c.curr;
            }
            return d > c.d;
        }
    };
};

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
