class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        int maxLen = 0;
        for (string w : wordDict) {
            maxLen = max(maxLen, (int)(w.size()));
            wordSet.insert(w);
        }
        
        return dfs(s, wordSet, maxLen);
    }
    
private:
    unordered_map<string, vector<string>> table;
    vector<string> dfs(string s, unordered_set<string>& wordSet, int maxLen) {
        if (table.find(s) != table.end()) {
            return table[s];
        }
        
        vector<string> result;        
        if (wordSet.find(s) != wordSet.end()) {
            result.push_back(s);
        }
        
        for (int i = 1; i <= maxLen && i < s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (wordSet.find(prefix) != wordSet.end()) {
                string suffix = s.substr(i);
                vector<string> temp = dfs(suffix, wordSet, maxLen);
                for (string t : temp) {
                    result.push_back(prefix + " " + t);
                }
            }
        }
        
        table[s] = result;
        return result;
    }
};
