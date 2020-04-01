class Solution {
public:
    int calculate(string s) {
        stack<int> St;
        int result = 0, num = 0, i = 0;
        int sign = 1;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                result += sign * num;
                num = 0;
            }
            else {
                if (s[i] == '+') {
                    sign = 1;
                }
                else if (s[i] == '-') {
                    sign = -1;
                }
                else if (s[i] == '(') {
                    St.push(sign);
                    St.push(result);
                    sign = 1;
                    result = 0;
                }
                else if (s[i] == ')') {
                    int prev = St.top();
                    St.pop();
                    sign = St.top();
                    St.pop();
                    result = prev + sign * result;
                }
                ++i;
            }
        }
        return result;
    }
};
