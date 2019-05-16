class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int start = 0, end = A.size() - 1;
        while (start < end) {
            if (A[start] & 1) {
                swap(A[start], A[end--]);
            }
            else {
                start += 1;
            }
        }
        return  A;
    }
};
