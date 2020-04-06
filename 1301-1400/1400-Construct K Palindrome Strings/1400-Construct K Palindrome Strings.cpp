class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) {
            return false;
        }
        vector<int> table(26);
        for (char c : s) {
            ++table[c - 'a'];
        }
        int oddCount = 0;
        for (int count : table) {
            if (count & 1) {
                ++oddCount;
            }
        }
        return oddCount <= k;
    }
};
