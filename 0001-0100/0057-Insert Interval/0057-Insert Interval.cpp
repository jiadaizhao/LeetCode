/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int i;
        for (i = 0; i < intervals.size(); ++i) {
            if (newInterval.start > intervals[i].end) {
                result.push_back(intervals[i]);
            }
            else if (newInterval.end < intervals[i].start) {
                break;
            }
            else {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
            }
        }
        
        result.push_back(newInterval);

        while (i < intervals.size()) {
            result.push_back(intervals[i++]);
        }
        
        return result;
    }
};
