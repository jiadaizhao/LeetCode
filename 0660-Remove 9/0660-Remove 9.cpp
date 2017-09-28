class Solution {
public:
    int newInteger(int n) {
        int result = 0;
        int base = 1;
        while (n)
        {
            result += (n % 9) * base;
            n /= 9;
            base *= 10;
        }
        
        return result;
    }
};
