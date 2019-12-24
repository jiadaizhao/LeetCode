class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        vector<int> table(26);
        unordered_map<string, int> count;
        int letter = 0, start = 0, maxCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (++table[s[i] - 'a'] == 1) {
                ++letter;
            }
            if (i - start + 1 > minSize) {
                if (--table[s[start++] - 'a'] == 0) {
                    --letter;
                }
            }

            if (i - start + 1 == minSize && letter <= maxLetters) {
                maxCount = max(maxCount, ++count[s.substr(start, minSize)]);
            }
        }
        
        return maxCount;
    }
};
