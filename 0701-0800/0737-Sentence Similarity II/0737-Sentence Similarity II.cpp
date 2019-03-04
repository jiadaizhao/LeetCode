class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        
        for (auto& p : pairs) {
            if (parent.find(p.first) == parent.end()) {
                parent[p.first] = p.first;
            }
            if (parent.find(p.second) == parent.end()) {
                parent[p.second] = p.second;
            }
            
            string p1 = findParent(p.first);
            string p2 = findParent(p.second);
            if (p1 != p2) {
                parent[p1] = p2;
            }            
        }
        
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) {
                continue;
            }
            
            if (!parent.count(words1[i]) || !parent.count(words2[i]) || findParent(words1[i]) != findParent(words2[i])) {
                return false;
            }
        }
        
        return true;
    }
    
private:
    unordered_map<string, string> parent;
    string findParent(string& s) {
        while (parent[s] != s) {
            parent[s] = parent[parent[s]] ;
            s = parent[s];
        }
        
        return s;
    }
};
