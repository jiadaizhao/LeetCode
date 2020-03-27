class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> mins, maxs;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            int currMin = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                currMin = min(currMin, matrix[i][j]);
            }
            mins.insert(currMin);
        }
        
        for (int j = 0; j < n; ++j) {
            int currMax = matrix[0][j];
            for (int i = 1; i < m; ++i) {
                currMax = max(currMax, matrix[i][j]);
            }
            maxs.insert(currMax);
        }
        
        vector<int> result;
        for (int num : mins) {
            if (maxs.count(num)) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};
