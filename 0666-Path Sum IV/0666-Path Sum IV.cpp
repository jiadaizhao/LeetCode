class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> sum(5, vector<int>(8));
        for (int num : nums) {
            int level = num / 100;
            int index = num % 100 / 10 - 1;
            int val = num % 10;
            sum[level][index] += sum[level - 1][index / 2] + val;
        }
        
        int result = 0;
        for (int i = 1; i < 5; ++i) {
            for (int j = 0; j < i * 2; ++j) {
                if (i == 4 || (sum[i][j] && !sum[i + 1][j * 2] && !sum[i + 1][j * 2 + 1])) {
                    result += sum[i][j];
                }
            }
        }
        
        return result;
    }
};
