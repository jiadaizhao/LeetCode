class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int table[5] = {};
        int maxCount = 0, count = 0;
        for (char c : croakOfFrogs) {
            auto index = string("croak").find(c);
            ++table[index];
            if (index == 0) {
                maxCount = max(maxCount, ++count);
            }
            else if (--table[index - 1] < 0) {
                return -1;
            }
            else if (c == 'k') {
                --count;
            }
        }
        
        return count == 0 ? maxCount : -1;
    }
};
