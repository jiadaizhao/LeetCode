class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> St;
        for (char c : expression) {
            if (c == ')') {
                unordered_set<char> visited;
                while (St.top() != '(') {
                    visited.insert(St.top());
                    St.pop();
                }

                St.pop();
                char op = St.top();
                St.pop();
                if (op == '&') {
                    if (visited.count('f')) {
                        St.push('f');
                    }
                    else {
                        St.push('t');
                    }
                }
                else if (op == '|') {
                    if (visited.count('t')) {
                        St.push('t');
                    }
                    else {
                        St.push('f');
                    }
                }
                else if (visited.count('t')) {
                    St.push('f');
                }
                else {
                    St.push('t');
                }
            }
            else if (c != ',') {
                St.push(c);
            }
        }

        return St.top() == 't';
    }
};
