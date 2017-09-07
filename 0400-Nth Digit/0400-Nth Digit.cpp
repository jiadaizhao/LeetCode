class Solution {
public:
    int findNthDigit(int n) {
        long count = 9;
        int base = 1;
        while (n - count * base > 0)
        {
            n -= count * base;
            count *= 10;
            ++base;
        }
        
        int index0 = (n - 1) / base;
        int index1 = (n - 1) % base;
        int target = pow(10, base - 1) + index0;
        return target / (int)pow(10, base - 1 - index1) % 10;
    }
};
