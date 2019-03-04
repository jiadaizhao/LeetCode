class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        
        reverse(s.begin() + start, s.end());
    }
};
