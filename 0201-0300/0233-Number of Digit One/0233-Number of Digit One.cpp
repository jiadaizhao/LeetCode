class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for (long base = 1; base <= n; base *= 10) {
            int curr = n / base % 10;
            int low = n % base;
            int high = n / (base * 10);
            if (curr < 1) {
                count += high * base;
            }
            else if (curr == 1) {
                count += high * base + low + 1;
            }
            else {
                count += (high + 1) * base;
            }
        }
        
        return count;
    }
};
