class Solution {
public:
    int scoreOfParentheses(string S) {
        int bal = 0, total = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                ++bal;
            }
            else {
                --bal;
                if (S[i - 1] == '(') {
                    total += 1 << bal;
                }
            }
        }
        return total;
    }
};
