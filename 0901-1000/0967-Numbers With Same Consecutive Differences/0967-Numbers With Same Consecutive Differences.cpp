class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> curr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < N - 1; ++i) {
            vector<int> next;
            for (int x : curr) {
                int d = x % 10;
                if (d - K >= 0) {
                    next.push_back(x * 10 + d - K);
                }
                if (K > 0 && d + K <= 9) {
                    next.push_back(x * 10 + d + K);
                }
            }
            swap(curr, next);
        }
        if (N == 1) {
            curr.push_back(0);
        }
        return curr;
    }
};
