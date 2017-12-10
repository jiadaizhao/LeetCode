class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int m = target.size();
        int candidate = 0;
        for (string& s : dictionary) {
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
        
        int minLen = INT_MAX;
        int minAbbr = 0;
        int bm = 1 << m;
        dfs(1, 0, bm, candidate, 1, minLen, minAbbr);

        string result;
        int prev = m - 1;
        for (int i = m - 1; i >= 0; --i) {
            if (minAbbr & 1) {
                if (prev - i > 0) {
                    result = to_string(prev - i) + result;
                }
                prev = i - 1;
                result = target[i] + result;
            }
            else if (i == 0) {
                result = to_string(prev + 1) + result;
            }
            minAbbr >>= 1;
        }

        return result;
    }
    
private:
    vector<int> dict;
    void dfs(int start, int mask, int bm, int candidate, int len, int& minLen, int& minAbbr) {
        if (len >= minLen) {
            return;
        }
        
        bool match = true;
        for (int& dm : dict) {
            if ((dm & mask) == 0) {
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
                    if (b == start || (b << 1) == bm) {
                        dfs(b << 1, mask | b, bm, candidate, len + 1, minLen, minAbbr);
                    }
                    else {
                        dfs(b << 1, mask | b, bm, candidate, len + 2, minLen, minAbbr);
                    }                    
                }
            }
        }
    }
};
