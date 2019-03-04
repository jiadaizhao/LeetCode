class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();        
        int start = 0, end = n - 1;
        while (start <= end && s[start] == ' ') {
            ++start;
        }
        
        if (start > end) {
            return false;
        }
        
        while (end >= start && s[end] == ' ') {
            --end;
        }
        
        if (s[start] == '+' || s[start] == '-') {
            ++start;
        }
        
        bool num = false, dot = false, exp = false;
        while (start <= end) {
            char c = s[start];
            if (isdigit(c)) {
                num = true;
            }
            else if (c == '.') {
                if (dot || exp) {
                    return false;
                }
                dot = true;
            }
            else if (c == 'e') {
                if (exp || !num) {
                    return false;
                }
                exp = true;
                num = false;
            }
            else if (c == '+' || c == '-') {
                if (s[start - 1] != 'e') {
                    return false;
                }
            }
            else {
                return false;
            }
            ++start;
        }
        
        return num;
    }
};
