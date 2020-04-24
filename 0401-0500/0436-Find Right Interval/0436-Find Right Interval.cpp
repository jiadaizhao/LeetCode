class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> result;
        map<int, int> table;
        for (int i = 0; i < intervals.size(); ++i) {
            table[intervals[i][0]] = i;
        }
        
        for (auto& interval : intervals) {
            auto it = table.lower_bound(interval[1]);
            result.push_back((it != table.end()) ? it->second : -1);
        }
        
        return result;
    }
};
