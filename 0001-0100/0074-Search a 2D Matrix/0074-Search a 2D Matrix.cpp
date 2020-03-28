class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int start = 0, end = m * n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[mid / n][mid % n] < target) {
                start = mid + 1;
            }
            else if (matrix[mid / n][mid % n] > target) {
                end = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
