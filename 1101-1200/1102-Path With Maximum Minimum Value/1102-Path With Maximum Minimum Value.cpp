class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int R = A.size(), C = A[0].size();
        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(A[0][0], 0, 0);
        A[0][0] = -1;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto [v, r, c] = pq.top();
            pq.pop();
            if (r == R - 1 && c == C - 1) {
                return v;
            }
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && A[nr][nc] >= 0) {
                    pq.emplace(min(v, A[nr][nc]), nr, nc);
                    A[nr][nc] = -1;
                }
            }
        }
        
        return -1;
    }
};
