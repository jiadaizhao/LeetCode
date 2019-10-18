class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int row = king[0], col = king[1];
        unordered_set<int> qs;
        for (auto q : queens) {
            qs.insert(q[0] * 8 + q[1]);
        }

        vector<vector<int>> result;
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int k = 0; k < 8; ++k) {
            for (int step = 1; step < 8; ++step) {
                int r = row + dr[k] * step;
                int c = col + dc[k] * step;
                if (r < 0 || r >= 8 || c < 0 || c >= 8) {
                    break;
                }
                if (qs.count(r * 8 + c)) {
                    result.push_back({r, c});
                    break;
                }
            }
        }

        return result;
    }
};
