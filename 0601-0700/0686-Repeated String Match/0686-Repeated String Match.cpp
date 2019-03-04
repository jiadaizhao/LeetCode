class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n = A.size();
        if (n == 0) {
            return -1;
        }
        int m = B.size();
        vector<int> lps(m);
        int i = 1;
        int len = 0;
        while (i < m) {
            if (B[i] == B[len]) {
                lps[i++] = ++len;
            }
            else if (len != 0) {
                len = lps[len - 1];
            }
            else {
                ++i;
            }
        }
        
        i = 0;
        int j = 0;
        while (i < n) {
            if (A[(i + j) % n] == B[j]) {
                ++j;
                if (j == m) {
                    return (i + j) / n + ((i + j) % n != 0 ? 1 : 0);
                }
            }
            else if (j != 0) {
                i += j - lps[j - 1];
                j = lps[j - 1];
            }
            else {
                ++i;
            }
        }
        
        return -1;   
    }
};

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n = A.size();
        int m = B.size();
        string s = A;
        while (s.size() < B.size()) {
            s += A;
        }
        s += A;
        int index = s.find(B);
        if (index == -1) {
            return -1;
        }
        return (index + m + n - 1) / n;
    }
};
