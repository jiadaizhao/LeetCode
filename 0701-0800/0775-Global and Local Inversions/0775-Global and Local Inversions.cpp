class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        int maxNum = A[0];
        for (int i = 0; i < n - 2; ++i) {
            maxNum = max(maxNum, A[i]);
            if (maxNum > A[i + 2]) return false;
        }

        return true;
    }
};
