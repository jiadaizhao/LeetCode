class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }
        
        vector<vector<int>> result(r, vector<int>(c));
        int index = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[index / c][index % c] = nums[i][j];
                ++index;
            }
        }
        
        return result;
    }
};
