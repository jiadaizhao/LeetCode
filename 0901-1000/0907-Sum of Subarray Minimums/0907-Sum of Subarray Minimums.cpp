class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        A.push_back(0);
        stack<int> St;
        long long total = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i < A.size(); ++i) {
            while (!St.empty() && A[St.top()] > A[i]) {
                int index = St.top();
                St.pop();
                int left = St.empty() ? -1 : St.top();
                total = (total + (long long)A[index] * (index - left) * (i - index)) % MOD;
            }
            St.push(i);
        }
        return total;
    }
};
