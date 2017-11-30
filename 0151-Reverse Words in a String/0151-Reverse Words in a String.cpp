class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (index != 0) {
                    s[index++] = ' ';
                }

                int j = i;
                while (i < s.size() && s[i] != ' ') {
                    s[index++] = s[i++];
                }
                reverse(s.begin() + index - (i - j), s.begin() + index);
            }
        }

        s.erase(s.begin() + index, s.end());
    }
};
