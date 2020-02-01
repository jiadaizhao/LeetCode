class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return 2;
            }
            ++left;
            --right;
        }
        return 1;
    }
};
