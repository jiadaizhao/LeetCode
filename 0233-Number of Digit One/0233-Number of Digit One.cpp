class Solution {
public:
    int countDigitOne(int n) {
        long long base = 1;
        int count = 0;
        while (n / base)
        {
            int curr = n / base % 10;
            int low = n % base;
            int high = n / (base * 10);
            if (curr < 1)
            {
                count += high * base;
            }
            else if (curr == 1)
            {
                count += high * base + low + 1;
            }
            else
            {
                count += (high + 1) * base;
            }
            base *= 10;
        }
        
        return count;
    }
};
