class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int maxLen = 1, inc = 1, dec = 1;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i - 1]) {
                inc = dec + 1;
                maxLen = max(maxLen, inc);
                dec = 1;
            }
            else if (A[i] < A[i - 1]) {
                dec = inc + 1;
                maxLen = max(maxLen, dec);
                inc = 1;
            }
            else {
                inc = dec = 1;
            }
        }
        return maxLen;
    }
};
