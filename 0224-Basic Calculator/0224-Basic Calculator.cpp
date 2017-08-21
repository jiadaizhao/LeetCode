class Solution {
public:
    int calculate(string s) {
        stack<int> vals;
        stack<int> ops;
        int num = 0;
        int sign = 1;
        int res = 0;
        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else
            {
                res += sign * num;
                num = 0;
                if (c == '+')
                {
                    sign = 1;
                }
                else if (c == '-')
                {
                    sign = -1;
                }
                else if (c == '(')
                {
                    vals.push(res);
                    ops.push(sign);
                    res = 0;
                    sign = 1;
                }
                else if (c == ')')
                {
                    res = vals.top() + ops.top() * res;
                    vals.pop();
                    ops.pop();
                }
            }                
        }
        
        res += sign * num;
        
        return res;
    }
};

// Convert to reversed polish notation
class Solution {
public:
    int calculate(string s) {
        vector<string> postexp = infixToPostfix(s);
        stack<int> St;
        for (string& exp : postexp)
        {
            if (isOperand(exp))
            {
                St.push(stoi(exp));
            }
            else
            {
                int data2 = St.top();
                St.pop();
                int data1 = St.top();
                St.pop();
                int result = 0;
                if (exp == "+")
                {
                    result = data1 + data2;
                }
                else
                {
                    result = data1 - data2;
                }

                St.push(result);
            }
        }
        
        return !St.empty() ? St.top() : 0;
    }
    
private:
    bool isOperand(string s) {
        return s.size() && s[0] >= '0' && s[1] <= '9';
    }

    vector<string> infixToPostfix(string& s) {
        stack<string> St;
        vector<string> result;
        int num = 0;
        bool hasNumber = false;
        for (char c : s)
        {
            if (isdigit(c))
            {
                hasNumber = true;
                num = num * 10 + (c - '0');
            }
            else
            {
                if (hasNumber)
                {
                    result.push_back(to_string(num));
                    hasNumber = false;
                    num = 0;
                }
                
                if (c == ' ')
                {
                    continue;
                }
                
                if (c == '(')
                {
                    St.push(string(1, c));
                }
                else if (c == ')')
                {
                    while (!St.empty() && St.top() != "(")
                    {
                        result.push_back(St.top());
                        St.pop();
                    }
                    St.pop();
                }
                else
                {
                    while (!St.empty() && St.top() != "(")
                    {
                        result.push_back(St.top());
                        St.pop();
                    }
                    St.push(string(1, c));
                }
            }
        }
        
        if (hasNumber)
        {
            result.push_back(to_string(num));
            hasNumber = false;
            num = 0;
        }
        
        while (!St.empty())
        {
            result.push_back(St.top());
            St.pop();
        }
        
        return result;
    }
};
