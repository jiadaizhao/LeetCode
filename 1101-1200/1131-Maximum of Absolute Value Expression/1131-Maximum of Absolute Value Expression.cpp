class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int maxVal = 0;
        int dx[4] = {-1, -1, 1, 1};
        int dy[4] = {-1, 1, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int minLocal = dx[i] * arr1[0] + dy[i] * arr2[0];
            for (int j = 1; j < arr1.size(); ++j) {
                int curr = dx[i] * arr1[j] + dy[i] * arr2[j] + j;
                maxVal = max(maxVal, curr - minLocal);
                minLocal = min(minLocal, curr);
            }
        }
        
        return maxVal;
    }
};
