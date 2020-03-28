class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), end = n - 1, count = 0;
        while (end >= 0 && s[end] == ' ') {
            --end;
        }
        
        while (end >= 0 && s[end] != ' ') {
            ++count;
            --end;
        }
        
        return count;
    }
};
