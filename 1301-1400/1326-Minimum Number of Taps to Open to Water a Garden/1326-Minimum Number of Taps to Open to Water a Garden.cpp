class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> area;
        for (int i = 0; i < ranges.size(); ++i) {
            if (ranges[i] > 0) {
                area.emplace_back(i - ranges[i], i + ranges[i]);
            }
        }
        sort(area.begin(), area.end());
        int left = 0, right = 0, i = 0, count = 0;
        while (i < area.size()) {
            if (area[i].first > left) {
                return -1;
            }
            right = max(right, area[i].second);
            ++count;
            while (i < area.size() && area[i].first <= left) {
                right = max(right, area[i++].second);
            }
            if (right >= n) {
                return count;
            }
            left = right;
        }
        return -1;
    }
};
