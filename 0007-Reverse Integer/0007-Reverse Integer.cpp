class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN || x == 0)
        {
            return 0;
        }
        long result = 0;
        int sign = (x > 0) ? 1 : -1;
        x = abs(x);
        while (x)
        {
            int val = x % 10;
            result = result * 10 + val;
            x /= 10;
        }
        
        result *= sign;
        if (result > INT_MAX || result < INT_MIN)
        {
            return 0;
        }
        
        return result;
    }
};
