class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> table;
        int maxCount = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            string s;
            for (int j = 0; j < matrix[i].size(); ++j) {
                s += (matrix[i][j] ^ matrix[i][0]) ? '1' : '0';
            }
            maxCount = max(maxCount, ++table[s]);
        }
        
        return maxCount;
    }
};
