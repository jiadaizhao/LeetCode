class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0, end = -1;
        for (auto& i : intervals) {
            if (i[1] > end) {
                ++count;
                end = i[1];
            }
        }
        return count;
    }
    
private:
    static bool cmp(vector<int>& i1, vector<int>& i2) {
        if (i1[0] == i2[0]) {
            return i1[1] > i2[1];
        }
        return i1[0] < i2[0];
    }
};
