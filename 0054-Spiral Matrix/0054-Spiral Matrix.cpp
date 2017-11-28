class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if (m == 0) {
            return result;
        }
        int n = matrix[0].size();
        int rowStart = 0, rowEnd = m - 1;
        int colStart = 0, colEnd = n - 1;
        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int j = colStart; j <= colEnd; ++j) {
                result.push_back(matrix[rowStart][j]);
            }
            ++rowStart;
            
            for (int i = rowStart; i <= rowEnd; ++i) {
                result.push_back(matrix[i][colEnd]);
            }
            --colEnd;
            
            if (rowStart <= rowEnd) {
                for (int j = colEnd; j >= colStart; --j) {
                    result.push_back(matrix[rowEnd][j]);
                }
                --rowEnd;
            }
            
            if (colStart <= colEnd) {
                for (int i = rowEnd; i >= rowStart; --i) {
                    result.push_back(matrix[i][colStart]);
                }
                ++colStart;
            }
        }
        
        return result;
    }
};
