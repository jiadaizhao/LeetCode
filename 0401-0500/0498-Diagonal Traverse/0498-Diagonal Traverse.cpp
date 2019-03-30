class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return {};
        }
        int n = matrix[0].size();
        vector<int> result(m * n);
        int row = 0, col = 0;
        for (int k = 0; k < result.size(); ++k) {
            result[k] = matrix[row][col];
            if ((row + col) & 1) {
                if (row == m - 1) {
                    col += 1;
                }
                else if (col == 0) {
                    row += 1;
                }
                else {
                    row += 1;
                    col -= 1;
                }
            }
            else {
                if (col == n - 1) {
                    row += 1;
                }
                else if (row == 0) {
                    col += 1;
                }
                else {
                    row -= 1;
                    col += 1;
                }
            }
        }
        
        return result;
    }
};
