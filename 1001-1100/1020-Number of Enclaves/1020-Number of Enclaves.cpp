class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        queue<pair<int, int>> Q;
        int total = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                if (A[i][j] == 1) {
                    if (i == 0 || i == A.size() - 1 || j == 0 || j == A[i].size() - 1) {
                        A[i][j] = 0;
                        Q.emplace(i, j);
                    }
                    else {
                        ++total;
                    }
                }
            }
        }
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!Q.empty()) {
            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = row + dr[k];
                int nc = col + dc[k];
                if (nr >= 0 && nr < A.size() && nc >= 0 && nc < A[0].size() && A[nr][nc] == 1) {
                    A[nr][nc] = 0;
                    Q.emplace(nr, nc);
                    --total;
                }
            }
        }
        
        return total;
    }
};
