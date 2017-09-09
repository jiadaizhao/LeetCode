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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](Interval& i1, Interval& i2){return i1.start < i2.start;});
        int count = 0;
        int prev = intervals[0].end;
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i].start < prev)
            {
                ++count;
                prev = min(prev, intervals[i].end);
            }
            else
            {
                prev = intervals[i].end;
            }
        }
        
        return count;
    }
};
