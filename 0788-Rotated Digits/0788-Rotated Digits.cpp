class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; ++i) {
            if (isValid(i)) {
                ++count;
            }
        }
        return count;
    }
    
private:
    bool isValid(int num) {
        int n = num, base = 1;
        int result = 0;
        while (n) {
            int temp = n % 10;
            if (temp == 2 || temp == 5) {
                temp = 7 - temp;
            }
            else if (temp == 6 || temp == 9) {
                temp = 15 - temp;
            }
            else if (temp != 0 && temp != 1 && temp != 8) {
                return false;
            }
            result += base * temp;
            base *= 10;
            n /= 10;
        }
        return result != num;
    }
};
