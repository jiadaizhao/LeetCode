class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        int bs = 0, bt = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    ++bs;
                    --i;
                }
                else if (bs > 0) {
                    --bs;
                    --i;
                }
                else {
                    break;
                }
            }
            
            while (j >= 0) {
                if (T[j] == '#') {
                    ++bt;
                    --j;
                }
                else if (bt > 0) {
                    --bt;
                    --j;
                }
                else {
                    break;
                }
            }
            
            if (i >= 0 && j >= 0 && S[i] != T[j]) {
                return false;
            }
            
            if ((i < 0) ^ (j < 0)) {
                return false;
            }
            --i;
            --j; 
        }
        return true;
    }
};
