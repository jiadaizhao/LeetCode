class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<tuple<int, int, int>> table;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                table.push_back({i + j, -i, nums[i][j]});
            }
        }
        sort(table.begin(), table.end());
        vector<int> result(table.size());
        for (int i = 0; i < table.size(); ++i) {
            result[i] = std::get<2>(table[i]);
        }
        return result;
    }
};
