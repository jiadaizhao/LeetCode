class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size(), n = A[0].size();
        vector<bool> sortedRow(m - 1);
        int count = 0, sortedNum = 0;
        for (int j = 0; j < n; ++j) {
            vector<bool> temp(sortedRow.begin(), sortedRow.end());
            bool deleteCol = false;
            int num = 0;
            for (int i = 0; i < m - 1; ++i) {
                if (!sortedRow[i]) {
                    if (A[i][j] > A[i + 1][j]) {
                        ++count;
                        deleteCol = true;
                        break;
                    }
                    else if (A[i][j] < A[i + 1][j]) {
                        temp[i] = true;
                        ++num;
                    }
                }
            }
            
            if (!deleteCol) {
                sortedRow = temp;
                sortedNum += num;
                if (sortedNum == m - 1) {
                    break;
                }
            }
        }
        
        return count;
    }
};
