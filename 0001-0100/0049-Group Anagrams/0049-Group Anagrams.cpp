class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> table;
        for (string& str : strs) {
            string s(str);
            sort(s.begin(), s.end());
            table[s].push_back(str);
        }
        
        for (auto t : table) {
            result.push_back(t.second);
        }
        
        return result;
    }
};
