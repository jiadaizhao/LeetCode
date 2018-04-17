class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        for (string s : banned) {
            ban.insert(s);
        }
        
        unordered_map<string, int> table;
        int n = paragraph.size(), i = 0;
        string s;
        while (i < n && !isalpha(paragraph[i])) {
            ++i;
        }
        while (i < n) {
            while (i < n && isalpha(paragraph[i])) {
                s += tolower(paragraph[i++]);
            }
            if (!ban.count(s)) {
                ++table[s];
            }            
            s = "";
            while (i < n && !isalpha(paragraph[i])) {
                ++i;
            }
        }
        string result;
        int maxCount = 0;
        for (auto t : table) {
            if (t.second > maxCount) {
                result = t.first;
                maxCount = t.second;
            }
        }
        return result;
    }
};
