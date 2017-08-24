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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> time;
        
        for (Interval i : intervals)
        {
            time.push_back({i.start, 1});
            time.push_back({i.end, 0});
        }
        
        sort(time.begin(), time.end(), cmp());
        int count = 0;
        int maxCount = 0;
        for (auto t : time)
        {
            if (t.second)
            {
                ++count;
            }
            else
            {
                --count;
            }
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
    
private:
    struct cmp {
        bool operator() (pair<int, int> p1, pair<int, int> p2)
        {
            if (p1.first == p2.first)
            {
                return p1.second < p2.second;
            }
            else
            {
                return p1.first < p2.first;
            }
        }
    };
};
