class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> right(A.size());
        right.back() = A.back();
        for (int i = A.size() - 2; i >= 0; --i) {
            right[i] = min(right[i + 1], A[i]);
        }
        
        int left = A[0];
        for (int i = 0; i < A.size() - 1; ++i) {
            left = max(left, A[i]);
            if (left <= right[i + 1]) {
                return i + 1;
            }
        }
        return -1;
    }
};
