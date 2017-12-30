class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int j = -1;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] > s[i + 1]) {
                j = i;
                break;
            }
        }
        
        if (j == -1) {
            return N;
        }
        
        for (int k = j; k >= 1; --k) {
            if (s[k - 1] > s[k] - 1) {
                --j;
            }
            else {
                break;
            }
        }
        
        --s[j];
        for (int k = j + 1; k < s.size(); ++k) {
            s[k] = '9';
        }
        return stoi(s);
    }
};
