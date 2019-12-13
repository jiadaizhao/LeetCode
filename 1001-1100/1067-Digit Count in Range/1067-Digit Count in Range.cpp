class Solution {
public:
    int digitsCount(int d, int low, int high) {
        return countDigit(d, high) - countDigit(d, low - 1);
    }
    
private:
    int countDigit(int d, int n) {
        if (d == 0 && n == 0) {
            return 1;
        }
        int count = 0;
        for (long base = 1; base <= n; base *= 10) {
            int curr = n / base % 10;
            int low = n % base;
            int high = n / (base * 10);
            if (d != 0) {
                if (curr < d) {
                    count += high * base;
                }
                else if (curr == d) {
                    count += high * base + low + 1;
                }
                else {
                    count += (high + 1) * base;
                }
            }
            else {
                if (base == 1) {
                    count += high + 1;
                }
                else if (high != 0) {
                    if (curr > 0) {
                        count += high * base;
                    }
                    else {
                        count += (high - 1) * base + low + 1;
                    }
                }
            }
        }
        
        return count;
    }
};
