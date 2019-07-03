class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        unordered_map<int, int> table;
        multimap<int, int> vl;
        for (int i = 0; i < values.size(); ++i) {
            vl.emplace(values[i], labels[i]);
        }

        int maxVal = 0;
        for (auto it = vl.rbegin(); num_wanted > 0 && it != vl.rend(); ++it) {
            if (table[it->second] < use_limit) {
                maxVal += it->first;
                ++table[it->second];
                --num_wanted;
            }
        }

        return maxVal;
    }
};
