class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        
        int end = n - 1;
        int count = 0;
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
