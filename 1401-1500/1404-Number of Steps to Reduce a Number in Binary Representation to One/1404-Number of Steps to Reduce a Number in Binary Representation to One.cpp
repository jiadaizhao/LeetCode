class Solution {
public:
    int numSteps(string s) {
        int zero = 0, start = 1, i = 1;
        while (i < s.size()) {
            if (s[i] == '1') {
                while (i < s.size() && s[i] == '1') {
                    ++i;
                }
                start = i;
            }
            else {
                while (i < s.size() && s[i] == '0') {
                    ++i;
                }
                if (i != s.size()) {
                    zero += i - start;
                }
            }
        }
        if (start == 1) {
            return s.size() - 1;
        }
        return zero + 1 + s.size();
    }
};


class Solution {
public:
    int numSteps(string s) {
        int start = 0, zero = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1') {
                zero += i - start - 1;
                start = i;
            }
        }
        if (start == 0) {
            return s.size() - 1;
        }
        return zero + 1 + s.size();
    }
};
