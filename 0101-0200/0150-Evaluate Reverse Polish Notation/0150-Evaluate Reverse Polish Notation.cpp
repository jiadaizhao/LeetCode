class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> St;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int val2 = St.top();
                St.pop();
                int val1 = St.top();
                St.pop();
                if (s == "+") {
                    St.push(val1 + val2);
                }
                else if (s == "-") {
                    St.push(val1 - val2);
                }
                else if (s == "*") {
                    St.push(val1 * val2);
                }
                else {
                    St.push(val1 / val2);
                }
            }
            else {
                St.push(stoi(s));
            }
        }
        
        return St.top();
    }
};
