class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        unordered_set<int> table;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                table.insert(fronts[i]);
            }
        }
        
        int output = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (!table.count(fronts[i])) {
                output = min(output, fronts[i]);
            }
            if (!table.count(backs[i])) {
                output = min(output, backs[i]);
            }
        }
        return output == INT_MAX ? 0 : output;
    }
};
