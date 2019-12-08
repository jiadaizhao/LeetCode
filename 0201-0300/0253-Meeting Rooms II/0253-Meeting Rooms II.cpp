class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> time;
        for (auto i : intervals) {
            time.emplace_back(i[0], 1);
            time.emplace_back(i[1], 0);
        }
        
        sort(time.begin(), time.end());
        int count = 0, maxCount = 0;
        for (auto& t : time) {
            if (t.second) {
                ++count;
                maxCount = max(maxCount, count);
            }
            else {
                --count;
            }            
        }
        return maxCount;
    }
};
