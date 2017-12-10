class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int i = 0;
        int n = s.size();
        while (i < n) {
            while (i < n && s[i] == ' ') {
                ++i;
            }
            
            if (i < n) {
                ++count;
            }
            
            while (i < n && s[i] != ' ') {
                ++i;
            }
        }
        
        return count;
    }
};
