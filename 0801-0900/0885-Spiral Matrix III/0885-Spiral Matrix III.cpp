class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int step = 1, sign = 1;
        vector<vector<int>> result = {{r0, c0}};
        int r = r0, c = c0;
        while (result.size() < R*C) {
            for (int i = 0; i < step; ++i) {
                c += sign;
                if (r >= 0 && r < R && c >= 0 && c < C) {
                    result.push_back({r, c});
                }
            }
            
            for (int i = 0; i < step; ++i) {
                r += sign;
                if (r >= 0 && r < R && c >= 0 && c < C) {
                    result.push_back({r, c});
                }
            }
            
            step += 1;
            sign *= -1;
        }
        
        return result;
    }
};
