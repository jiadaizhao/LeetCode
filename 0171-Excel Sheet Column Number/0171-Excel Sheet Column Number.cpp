class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int c : s)
        {
            int i = c - 'A' + 1;
            result = result * 26 + i;
        }
        
        return result;
    }
};
