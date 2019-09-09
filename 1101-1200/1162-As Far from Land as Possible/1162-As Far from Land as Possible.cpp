class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        queue<pair<int, int>> Q;
        unordered_set<int> visited;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    Q.emplace(i, j);
                    visited.insert(i * N + j);
                }
            }
        }

        int maxD = -1;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!Q.empty()) {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int row = Q.front().first;
                int col = Q.front().second;
                Q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];
                    if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited.count(nr * N + nc)) {
                        Q.emplace(nr, nc);
                        visited.insert(nr * N + nc);
                    }
                }
            }

            ++maxD;
        }

        return (maxD <= 0) ? -1 : maxD;
    }
};
