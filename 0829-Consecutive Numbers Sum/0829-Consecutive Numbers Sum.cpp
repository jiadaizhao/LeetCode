class Solution {
public:
    int consecutiveNumbersSum(int N) {
        N *= 2;
        int count = 1;
        for (int i = 2; i * i <= N; ++i) {
            if (N % i == 0 && ((i & 1) ^ (N / i & 1))) {
                ++count;
            }
        }
        return count;
    }
};
