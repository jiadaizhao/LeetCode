int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> Q;
        bool found = false;
        for (int i = 0; i < m && !found; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1) {
                    dfs(A, i, j, Q);
                    found = true;
                    break;
                }
            }
        }
        
        int count = 0;
        while (!Q.empty()) {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int row = Q.front().first, col = Q.front().second;
                Q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (A[nr][nc] == 1) {
                            return count;
                        }
                        else if (A[nr][nc] == 0) {
                            A[nr][nc] = 2;
                            Q.emplace(nr, nc);
                        }
                    }
                }
            }
            ++count;
        }
        
        return -1;
    }
    
private:
    void dfs(vector<vector<int>>& A, int row, int col, queue<pair<int, int>>& Q) {
        int m = A.size(), n = A[0].size();
        A[row][col] = 2;
        Q.emplace(row, col);
        for (int i = 0; i < 4; ++i) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && A[nr][nc] == 1) {
                dfs(A, nr, nc, Q);
            }
        }
    }
};
