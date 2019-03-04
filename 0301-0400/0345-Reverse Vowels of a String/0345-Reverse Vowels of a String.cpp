class Solution {
public:
    string reverseVowels(string s) {
        if (s.size() == 0) {
            return s;
        }
        
        int start = 0, end = s.size() - 1;
        while (start < end) {
            while (start < end && !isVowel(s[start])) {
                ++start;
            }
            
            while (start < end && !isVowel(s[end])) {
                --end;
            }
            
            if (start < end) {
                swap(s[start], s[end]);
                ++start;
                --end;
            }            
        }
        
        return s;
    }
    
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
