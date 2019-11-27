class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        for (int i = 0; i < s1.size(); ++i) {
            char c1 = s1[i];
            char c2 = s2[i];
            if (c1 != c2) {
                if (c1 == 'x') {
                    ++x1;
                }
                else {
                    ++y1;
                }
                
                if (c2 == 'x') {
                    ++x2;
                }
                else {
                    ++y2;
                }
            }
        }
        
        if ((x1 + x2) & 1 || (y1 + y2) & 1) {
            return -1;
        }
        
        return x1 / 2 + y1 / 2 + (x1 & 1) * 2;
    }
};
