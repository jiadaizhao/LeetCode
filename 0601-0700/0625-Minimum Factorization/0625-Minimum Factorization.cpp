class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 2) {
            return a;
        }
        long result = 0, base = 1;
        for (int i = 9; i >= 2; --i) {
            while (a % i == 0) {
                result += i * base;
                base *= 10;
                a /= i;
            }
        }
        
        return (a == 1 && result <= INT_MAX) ? result : 0;
    }
};
