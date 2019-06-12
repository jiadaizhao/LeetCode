class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        vector<vector<int>> presum(matrix.size(), vector<int>(1 + matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                presum[i][j + 1] = presum[i][j] + matrix[i][j];
            }
        }

        int total = 0;
        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int i = 0; i <= j; ++i) {
                int curr = 0;
                unordered_map<int, int> table;
                table[0] = 1;
                for (int k = 0; k < matrix.size(); ++k) {
                    curr += presum[k][j + 1] - presum[k][i];
                    total += table[curr - target];
                    ++table[curr]; 
                }
            }
        }

        return total;
    }
};
