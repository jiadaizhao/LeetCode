class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        unordered_map<string, int> table;
                
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (table.find(accounts[i][j]) == table.end()) {
                    table[accounts[i][j]] = i;
                }
                else {
                    int i1 = table[accounts[i][j]];
                    int p1 = findParent(parent, i1);
                    int p2 = findParent(parent, i);
                    if (p1 != p2) {
                        parent[p1] = p2;
                    }
                }
            }
        }
        
        unordered_map<int, unordered_set<string>> result;
        for (int i = 0; i < n; ++i) {
            int index = findParent(parent, i);
            for (int j = 1; j < accounts[i].size(); ++j) {
                result[index].insert(accounts[i][j]);
            }            
        }
        
        vector<vector<string>> res;
        for (auto r : result) {
            vector<string> path = {accounts[r.first][0]};
            for (auto s : r.second) {
                path.push_back(s);
            }
            
            sort(path.begin() + 1, path.end());
            res.push_back(path);
        }
        
        return res;
    }
    
private:
    int findParent(vector<int>& parent, int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
};