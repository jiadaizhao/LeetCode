class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        
        unordered_set<string> table;
        for (auto& p : pairs) {
            table.insert(p.first + "#" + p.second);
        }
        
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) {
                continue;
            }
            
            string s1 = words1[i] + "#" + words2[i];
            string s2 = words2[i] + "#" + words1[i];
            if (table.find(s1) == table.end() && table.find(s2) == table.end()) {
                return false;
            }
        }
        
        return true;
    }
};
