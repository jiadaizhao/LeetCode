class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
        {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0)
        {
            return false;
        }
        
        // Start from left bottom or right top element
        int row = m - 1, col = 0;
        while (row >= 0 && col < n)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            
            if (matrix[row][col] < target)
            {
                ++col;
            }
            else
            {
                --row;
            }
        }
        
        return false;
    }
};
