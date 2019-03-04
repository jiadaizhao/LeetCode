class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int m = target.size();
        vector<int> dict;
        int candidate = 0;
        for (string s : dictionary) {
            if (s.size() != m) {
                continue;
            }
            int mask = 0;
            for (int i = m - 1, b = 1; i >= 0; --i, b <<= 1) {
                if (s[i] != target[i]) {
                    mask |= b;
                }
            }
            dict.push_back(mask);
            candidate |= mask;
        }
        
        int bm = 1 << m;
        int minLen = m;
        int minAbbr = (1 << m) - 1;
        dfs(dict, 1, 0, bm, candidate, 1, minLen, minAbbr);

        string result;
        int prev = 0;
        int b = (1 << (m - 1));
        for (int i = 0; i < m; ++i) {
            if (minAbbr & b) {
                if (i - prev > 0) {
                    result += to_string(i - prev);
                }
                prev = i + 1;
                result += target[i];
            }
            else if (i == m - 1) {
                result += to_string(m - prev);
            }
            b >>= 1;
        }
        
        return result;
    }
    
private:
    void dfs(vector<int>& dict, int start, int mask, int bm, int candidate, int len, int& minLen, int& minAbbr) {
        if (len >= minLen) {
            return;
        }
        
        bool match = true;
        for (int dm : dict) {
            if ((mask & dm) == 0) {
                match = false;
                break;
            }
        }
        
        if (match) {
            minLen = len;
            minAbbr = mask;
        }
        else {
            for (int b = start; b < bm; b <<= 1) {
                if (candidate & b) {
                    int nextLen;
                    if (b == start && (b << 1) == bm) {
                        nextLen = len;
                    }
                    else if (b == start || (b << 1) == bm) {
                        nextLen = len + 1;
                    }
                    else {
                        nextLen = len + 2;
                    }
                    dfs(dict, b << 1, mask | b, bm, candidate, nextLen, minLen, minAbbr);
                }
            }
        }
    }
};
