class Solution {
public:
    string intToRoman(int num) {
        vector<int> radix = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result = "";
        for (int i = 0; num > 0; ++i) {
            int count = num / radix[i];
            while (count) {
                result += symbol[i];
                --count;
            }
            
            num %= radix[i];
        }
        
        return result;
    }
};
