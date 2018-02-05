class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int end1 = intervals[0][1] - 1, end2 = intervals[0][1];
        int count = 2;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > end2) {                
                count += 2;                
                end1 = intervals[i][1] - 1;
                end2 = intervals[i][1];
            }
            else if (intervals[i][0] > end1) {
                ++count;                
                end1 = (intervals[i][1] > end2) ? end2 : end2 - 1;
                end2 = intervals[i][1];
            }
        }
        
        return count;
    }
    
private:
    struct cmp {
        bool operator() (const vector<int>& i1, const vector<int>& i2) const {
            if (i1[1] == i2[1]) {
                return i1[0] < i2[0];
            }
            else {
                return i1[1] < i2[1];
            }
        }
    };
};
