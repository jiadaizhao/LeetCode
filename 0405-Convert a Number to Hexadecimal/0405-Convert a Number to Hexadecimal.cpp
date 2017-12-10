class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        unsigned int n = num;
        string result;
        while (n) {
            int temp = n % 16;
            if (temp > 9) {
                result += 'a' + (temp - 10);
            }
            else {
                result += '0' + temp;
            }
            n /= 16;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
