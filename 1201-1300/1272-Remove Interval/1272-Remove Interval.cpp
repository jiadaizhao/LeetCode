class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> result;
        int start = toBeRemoved[0], end = toBeRemoved[1];
        for (auto& i : intervals) {
            int a = i[0], b = i[1];
            if (start >= b || end <= a) {
                result.push_back({a, b});
            }
            else {
                if (start > a) {
                    result.push_back({a, start});
                }
                if (end < b) {
                    result.push_back({end, b});
                }
            }
        }
        
        return result;
    }
};
