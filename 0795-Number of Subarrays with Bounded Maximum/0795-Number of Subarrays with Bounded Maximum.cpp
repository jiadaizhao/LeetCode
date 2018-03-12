class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int count = 0;
        int maxIndex = -1, minIndex = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] >= L) {
                minIndex = i;
            }
            if (A[i] > R) {
                maxIndex = i;
            }
            count += minIndex - maxIndex;
        }
        return count;
    }
};
