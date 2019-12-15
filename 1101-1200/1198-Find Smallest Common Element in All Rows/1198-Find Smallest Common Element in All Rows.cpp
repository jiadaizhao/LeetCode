class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int> table(10001);
        for (auto& row : mat) {
            for (int val : row) {
                if (++table[val] == mat.size()) {
                    return val;
                }
            }
        }
        
        return -1;
    }
};
