class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> result(2, vector<int>(colsum.size()));
        for (int j = 0; j < colsum.size(); ++j) {
            if (colsum[j] == 2) {
                result[0][j] = result[1][j] = 1;
                --upper;
                --lower;
            }
            else if (colsum[j] == 1) {
                if (upper >= lower) {
                    result[0][j] = 1;
                    --upper;
                }
                else {
                    result[1][j] = 1;
                    --lower;
                }
            }
            if (upper < 0 || lower < 0) {
                return {};
            }
        }
        
        if (upper == 0 && lower == 0) {
            return result;
        }
        else {
            return {};
        }
    }
};
