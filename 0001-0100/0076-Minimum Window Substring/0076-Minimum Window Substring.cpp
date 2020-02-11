class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        for (char c : t) {
            ++table[c];
        }
        int count = table.size(), start = 0;
        int minSize = s.size() + 1;
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (--table[s[i]] == 0) {
                --count;
            }
            while (count == 0) {
                if (i - start + 1 < minSize) {
                    minSize = i - start + 1;
                    result = s.substr(start, minSize);
                }
                if (++table[s[start++]] == 1) {
                    ++count;
                }
            }
        }
        
        return result;
    }
};
