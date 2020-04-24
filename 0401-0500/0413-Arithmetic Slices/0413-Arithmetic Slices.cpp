class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int total = 0, count = 0;
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                ++count;
            }
            else {
                total += count * (count + 1) / 2;
                count = 0;
            }
        }
        total += count * (count + 1) / 2;
        return total;
    }
};
