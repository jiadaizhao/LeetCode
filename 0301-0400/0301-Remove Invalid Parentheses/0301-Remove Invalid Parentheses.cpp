class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        removeParantheses(s, 0, 0, '(', ')', result);
        return result;
    }
    
private:
    void removeParantheses(string s, int lastLeft, int lastRight, char left, char right, vector<string>& result) {
        for (int p = 0, i = lastLeft; i < s.size(); ++i) {
            if (s[i] == left) {
                ++p;
            }
            else if (s[i] == right) {
                --p;
            }
            if (p >= 0) {
                continue;
            }
            for (int j = lastRight; j <= i; ++j) {
                if (s[j] == right && (j == lastRight || s[j - 1] != right)) {
                    removeParantheses(s.substr(0, j) + s.substr(j + 1), i, j, left, right, result);
                }
            }
            
            return;
        }
        
        
        if (left == '(') {
            string revs(s);
            reverse(revs.begin(), revs.end());
            removeParantheses(revs, 0, 0, right, left, result);
        }
        else {
            result.push_back(revs);
        }
    }
};
