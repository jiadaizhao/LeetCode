class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int MOD = 1000000007;
        sort(A.begin(), A.end());
        int total = 0;
        long long c = 1;
        for (int i = 0; i < A.size(); ++i) {
            total = (total + A[i] * c - A[A.size() - i - 1] * c) % MOD;
            c = (c * 2) % MOD;
        }
        return total;
    }
};
