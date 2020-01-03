/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> intervals;
        for (auto s : schedule) {
            for (Interval i : s) {
                intervals.push_back(i);
            }
        }
        
        sort(intervals.begin(), intervals.end(), cmp());
        int prevEnd = intervals[0].end;        
        vector<Interval> result;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > prevEnd) {
                result.push_back({prevEnd, intervals[i].start});
            }
                        
            if (intervals[i].end > prevEnd) {
                prevEnd = intervals[i].end;
            }
        }
        
        return result;
    }
    
private:
    struct cmp {
        bool operator() (Interval& i1, Interval& i2) {
            return i1.start < i2.start;
        }    
    };
};
