class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int, int>> table;
        for (int i = 0; i < mat.size(); ++i) {
            table.insert({accumulate(mat[i].begin(), mat[i].end(), 0), i});
        }
        vector<int> result;
        for (auto it = table.begin(); k-- > 0; ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};
