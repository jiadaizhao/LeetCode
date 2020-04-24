class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int count = 0, prev = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prev) {
                ++count;
                prev = min(prev, intervals[i][1]);
            }
            else {
                prev = intervals[i][1];
            }
        }
        
        return count;
    }
};
