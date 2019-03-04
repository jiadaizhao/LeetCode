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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> result;
        map<int, int> table;
        for (int i = 0; i < intervals.size(); ++i) {
            table[intervals[i].start] = i;
        }
        
        for (Interval& interval : intervals) {
            auto it = table.lower_bound(interval.end);
            result.push_back((it != table.end()) ? it->second : -1);
        }
        
        return result;
    }    
};
