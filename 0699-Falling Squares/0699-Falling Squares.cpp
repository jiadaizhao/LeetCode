class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        int n = positions.size();
        vector<int> result(n);
        vector<Interval> intervals;
        int maxh = 0;
        for (int i = 0; i < n; ++i) {
            int left = positions[i].first;
            int right = positions[i].first + positions[i].second - 1;
            int currh = getHeight(intervals, left, right) + right - left + 1;
            intervals.emplace_back(left, right, currh);
            maxh = max(maxh, currh);
            result[i] = maxh;
        }
        return result;
    }
    
private:
    class Interval {
    public:
        int left;
        int right;
        int height;
        Interval(int l, int r, int h): left(l), right(r), height(h) {}
    };
    int getHeight(vector<Interval>& intervals, int left, int right) {
        int h = 0;
        for (Interval& interval : intervals) {
            if (interval.right < left || interval.left > right) {
                continue;
            }
            h = max(h, interval.height);
        }
        return h;
    }
};
