class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int i = 0;
        long long n = 0;
        while (n < K) {
            if (isdigit(S[i])) {
                n *= S[i] - '0';
            }
            else {
                n += 1;
            }
            i += 1;
        }
        
        string result;
        while (i--) {
            K %= n;
            if (K == 0 && isalpha(S[i])) {
                result = string(1, S[i]);
                break;
            }
            if (isdigit(S[i])) {
                n /= S[i] - '0';
            }
            else {
                n -= 1;
            }
        }
        return result;
    }
};
