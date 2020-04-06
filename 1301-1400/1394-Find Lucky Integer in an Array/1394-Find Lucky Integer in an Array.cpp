class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> table;
        for (int a : arr) {
            ++table[a];
        }
        int result = -1;
        for (auto& p : table) {
            if (p.first == p.second) {
                result = max(result, p.second);
            }
        }
        return result;
    }
};
