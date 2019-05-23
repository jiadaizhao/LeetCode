class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int table[26];
        for (int i = 0; i < order.size(); ++i) {
            table[order[i] - 'a'] = i;
        }
        
        for (int i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i], word2 = words[i + 1];
            int j = 0;
            while (j < words[i].size() && j < words[i + 1].size()) {
                if (table[words[i][j] - 'a'] < table[words[i + 1][j] - 'a']) {
                    break;
                }
                if (table[words[i][j] - 'a'] > table[words[i + 1][j] - 'a']) {
                    return false;
                }
                ++j;
            }
            
            if (j < words[i].size() && j == words[i + 1].size()) {
                return false;
            }
        }
        
        return true;
    }
};
