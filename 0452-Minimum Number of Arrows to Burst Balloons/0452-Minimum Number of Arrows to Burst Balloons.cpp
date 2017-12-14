class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n == 0) {
            return 0;
        }
        sort(points.begin(), points.end());
        int count = 1;
        int prev = points[0].second;
        for (int i = 1; i < n; ++i) {
            if (points[i].first > prev) {
                ++count;
                prev = points[i].second;
            }
            else {
                prev = min(prev, points[i].second);
            }
        }
        
        return count;
    }
};
