class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> preserve(n, INT_MAX), swap(n, INT_MAX);
        preserve[0] = 0;
        swap[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                preserve[i] = preserve[i - 1];
                swap[i] = swap[i - 1] + 1;
            }
            
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                preserve[i] = min(preserve[i], swap[i - 1]);
                swap[i] = min(swap[i], preserve[i - 1] + 1);
            }
        }
        return min(preserve[n - 1], swap[n - 1]);
    }
};
