class Solution {
public:
    bool isValid(string s) {
        stack<char> St;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                St.push(c);
            }
            else
            {
                if (St.empty())
                {
                    return false;
                }
                
                if ((c == ')' && St.top() != '(') ||
                    (c == '}' && St.top() != '{') ||
                    (c == ']' && St.top() != '['))
                {
                    return false;
                }
                
                St.pop();
            }
        }
        
        return St.empty();
    }
};
