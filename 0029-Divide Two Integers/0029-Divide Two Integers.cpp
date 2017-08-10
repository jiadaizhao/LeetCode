class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
        {
            return 0;
        }
        
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        
        int sign;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        {
            sign = 1;
        }
        else
        {
            sign = 0;
        }
        
        long a = abs((long)dividend), b = abs((long)divisor);
        int result = 0;
        while (a >= b)
        {
            int shift = 0;
            while (a >= (b << shift))
            {
                ++shift;
            }
            result += 1 << (shift - 1);
            a -= b << (shift - 1);
        }
        
        return sign ? result : -result;
    }
};
