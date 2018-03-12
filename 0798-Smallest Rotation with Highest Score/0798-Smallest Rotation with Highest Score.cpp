class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size();
        vector<int> bad(n);
        for (int i = 0; i < n; ++i) {
            int left = (i - A[i] + 1 + n) % n;
            int right = (i + 1) % n;
            --bad[left];
            ++bad[right];
            if (left > right) {
                --bad[0];
            }
        }
        int best = -n, result = 0, curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += bad[i];
            if (curr > best) {
                result = i;
                best = curr;
            }
        }
        return result;
    }
};
