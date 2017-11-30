class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> St;
        int num = 0;
        char preop = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (i == n - 1 || (!isdigit(c) && c != ' ')) {
                if (preop == '+') {
                    St.push(num);
                }
                else if (preop == '-') {
                    St.push(-num);
                }
                else if (preop == '*') {
                    int temp = St.top();
                    St.pop();
                    St.push(temp * num);
                }
                else {
                    int temp = St.top();
                    St.pop();
                    St.push(temp / num);
                }
                
                preop = c;
                num = 0;
            }
        }
        
        int result = 0;
        while (!St.empty()) {
            result += St.top();
            St.pop();
        }
        
        return result;
    }
};
