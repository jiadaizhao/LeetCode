class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        
        int sign = 1;
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) {
            sign = -1;
        }
        
        long a = abs((long)dividend), b = abs((long)divisor);
        long result = 0;
        while (a >= b) {
            int shift = 0;
            while ((b << shift) <= a) {
                ++shift;
            }
            result += 1LL << (shift - 1);
            a -= b << (shift - 1);
        }
        
        return sign == 1 ? (result > INT_MAX ? INT_MAX : result) : -result;
    }
};
