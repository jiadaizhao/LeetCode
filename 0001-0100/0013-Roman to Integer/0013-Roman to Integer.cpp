class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int curr, prev;
        for (int i = 0; i < s.size(); ++i) {
            curr = romanMap(s[i]);
            if (i != 0 && curr > prev) {
                result += curr - 2 * prev;
            }
            else {
                result += curr;
            }
            prev = curr;
        }
        
        return result;
    }
    
private:
    int romanMap(char c) {
        int result = 0;
        switch (c) {
            case 'I':
                result = 1;
                break;
            case 'V':
                result = 5;
                break;
            case 'X':
                result = 10;
                break;
            case 'L':
                result = 50;
                break;
            case 'C':
                result = 100;
                break;
            case 'D':
                result = 500;
                break;
            case 'M':
                result = 1000;
                break;
            default:
                break;
        }
        
        return result;
    }
};
