class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        return bfs(blocked, source, target) && bfs(blocked, target, source);
    }
    
private:
    bool bfs(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> block;
        for (auto b : blocked) {
            block.insert(b[0] * 1000000LL + b[1]);
        }
        int limit = blocked.size() * (blocked.size() - 1) / 2;
        queue<pair<int, int>> Q;
        Q.emplace(source[0], source[1]);
        block.insert(source[0] * 1000000LL + source[1]);
        int area = 0;
        static int dr[4] = {-1, 1, 0, 0};
        static int dc[4] = {0, 0, -1, 1};
        while (!Q.empty()) {
            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();
            ++area;
            if (area > limit) {
                return true;
            }
            for (int k = 0; k < 4; ++k) {
                int nr = row + dr[k];
                int nc = col + dc[k];
                if (nr >= 0 && nr < 1000000 && nc >= 0 && nc < 1000000 && !block.count(nr*1000000LL + nc)) {
                    if (nr == target[0] && nc == target[1]) {
                        return true;
                    }
                    Q.emplace(nr, nc);
                    block.insert(nr*1000000LL + nc);
                }
            }
        }
        
        return false;
    }
};
