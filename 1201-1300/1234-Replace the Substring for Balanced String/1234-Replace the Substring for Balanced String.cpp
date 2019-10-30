class Solution {
public:
    int balancedString(string s) {
        int target = s.size() / 4;
        unordered_map<char, int> counts;
        for (char c : s) {
            ++counts[c];
        }
        int start = 0, minLen = s.size();
        for (int i = 0; i < s.size(); ++i) {
            --counts[s[i]];
            while (start < s.size() && counts['Q'] <= target &&
                counts['W'] <= target && counts['E'] <= target &&
                counts['R'] <= target) {
                minLen = min(minLen, i - start + 1);
                ++counts[s[start++]];
            }
        }

        return minLen;
    }
};
