class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result(A.size());
        int left = 0, right = A.size() - 1;
        for (int i = A.size() - 1; i >= 0; --i) {
            if (A[left] * A[left] <= A[right] * A[right]) {
                result[i] = A[right] * A[right];
                --right;
            }
            else {
                result[i] = A[left] * A[left];
                ++left;
            }
        }

        return result;
    }
};
