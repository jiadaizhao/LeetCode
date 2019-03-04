class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return isPalindrome(s.substr(start, end - start)) || isPalindrome(s.substr(start + 1, end - start));
            }
            ++start;
            --end;
        }
        
        return true;
    }
    
private:
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        
        return true;
    }
};
