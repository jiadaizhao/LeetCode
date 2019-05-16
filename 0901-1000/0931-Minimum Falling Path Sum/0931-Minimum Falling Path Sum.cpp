class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                int prev = A[i - 1][j];
                if (j > 0) {
                    prev = min(prev, A[i - 1][j - 1]);
                }
                if (j < A.size() - 1) {
                    prev = min(prev, A[i - 1][j + 1]);
                }
                A[i][j] += prev;
            }
        }
        return *min_element(A[A.size() - 1].begin(), A[A.size() - 1].end());
    }
};
