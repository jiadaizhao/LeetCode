class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return dfs(input);
    }
    
private:
    unordered_map<string, vector<int>> table;
    vector<int> dfs(string s) {
        if (table.find(s) != table.end()) {
            return table[s];
        }
        
        vector<int> result;
        
        for (int i = 0; i < s.size(); ++i) {
            if (!isdigit(s[i])) {
                vector<int> left = dfs(s.substr(0, i));
                vector<int> right = dfs(s.substr(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (s[i] == '+') {
                            result.push_back(l + r);
                        }
                        else if (s[i] == '-') {
                            result.push_back(l - r);
                        }
                        else if (s[i] == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        if (result.size() == 0) {
            result.push_back(stoi(s));
        }
        
        return table[s] = result;
    }
};
