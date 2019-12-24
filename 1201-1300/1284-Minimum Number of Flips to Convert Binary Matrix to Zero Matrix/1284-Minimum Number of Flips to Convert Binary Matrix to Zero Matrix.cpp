class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int state = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    state |= (1 << (i * n + j));
                }                
            }
        }
        queue<int> Q;
        Q.push(state);
        unordered_set<int> visited;
        visited.insert(state);
        int step = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!Q.empty()) {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int curr = Q.front();
                Q.pop();
                if (curr == 0) {
                    return step;
                }
                for (int r = 0; r < m; ++r) {
                    for (int c = 0; c < n; ++c) {
                        state = curr ^ (1 << (r * n + c));
                        for (int k = 0; k < 4; ++k) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                                state ^= (1 << (nr * n + nc));
                            }
                        }
                        
                        if (!visited.count(state)) {
                            Q.push(state);
                            visited.insert(state);
                        }
                    }
                }
            }
            ++step;
        }
        
        return -1;
    }
};
