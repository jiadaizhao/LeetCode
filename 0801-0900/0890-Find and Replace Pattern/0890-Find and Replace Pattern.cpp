class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for (string& word : words) {
            unordered_map<char, char> table;
            unordered_set<char> mapped;
            bool match = true;
            for (int i = 0; i < pattern.size(); ++i) {
                if (!table.count(pattern[i])) {
                    if (mapped.count(word[i])) {
                        match = false;
                        break;
                    }
                    table[pattern[i]] = word[i];
                    mapped.insert(word[i]);
                }
                else if (table[pattern[i]] != word[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(word);
            }
        }
        return result;
    }
};
