class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> table;
        vector<vector<int>> result;
        for (int i = 0; i < groupSizes.size(); ++i) {
            if (groupSizes[i] == 1) {
                result.push_back({i});
            }
            else {
                table[groupSizes[i]].push_back(i);
            }
        }
        
        for (auto& p : table) {
            for (int i = 0; i < p.second.size(); i += p.first) {
                result.push_back(vector<int>(p.second.begin() + i, p.second.begin() + i + p.first));
            }
        }
        return result;
    }
};
