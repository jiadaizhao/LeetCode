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
        int start = 0, end = m * n - 1;
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] < target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        return matrix[start / n][start % n] == target ||
               matrix[end / n][end % n] == target;
    }
};
