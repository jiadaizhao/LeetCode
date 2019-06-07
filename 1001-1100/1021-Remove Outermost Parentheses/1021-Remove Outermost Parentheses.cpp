class Solution {
public:
    string removeOuterParentheses(string S) {
        string result;
        int bal = 0;
        for (char c : S) {
            if (c == '(') {
                if (bal++ > 0) {
                    result += c;
                }
            }
            else if (bal-- > 1) {
                result += c;
            }
        }
        return result;
    }
};
