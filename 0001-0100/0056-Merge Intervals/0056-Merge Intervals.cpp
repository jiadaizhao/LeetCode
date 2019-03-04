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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& i1, Interval& i2){return i1.start < i2.start;});
        vector<Interval> result;
        for (Interval i : intervals) {
            if (result.size() && result.back().end >= i.start) {
                result.back().end = max(result.back().end, i.end);
            }
            else {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
