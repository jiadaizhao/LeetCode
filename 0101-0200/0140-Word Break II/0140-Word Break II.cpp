class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int maxLen = 0;
        for (string& word : wordDict) {
            maxLen = max(maxLen, (int)(word.size()));
            dict.insert(word);
        }
        
        return dfs(s, dict, maxLen);        
    }
    
private:
    unordered_map<string, vector<string>> table;
    vector<string> dfs(string s, unordered_set<string>& dict, int& maxLen) {
        if (table.count(s)) {
            return table[s];
        }
        
        vector<string> result;
        if (dict.count(s)) {
            result.push_back(s);
        }

        for (int i = 1; i <= maxLen && i < s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (dict.count(prefix)) {
                string suffix = s.substr(i);
                vector<string> temp = dfs(suffix, dict, maxLen);
                for (string s : temp) {
                    result.push_back(prefix + " " + s);
                }
            }                        
        }
        
        return table[s] = result;
    }    
};
