class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int minNum = A[0], maxNum = A.back();
        int result = maxNum - minNum;
        for (int i = 0; i < A.size() - 1; ++i) {
            result = min(result, max(A.back() - K, A[i] + K) - min(A[0] + K, A[i + 1] - K));
        }
        return result;
    }
};
