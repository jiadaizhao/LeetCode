class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> table;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                table[i - j].push_back(mat[i][j]);
            }
        }
        
        for (auto& p : table) {
            sort(p.second.begin(), p.second.end(), greater<int>());
        }
        
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = table[i - j].back();
                table[i - j].pop_back();
            }
        }
        
        return result;
    }
};
