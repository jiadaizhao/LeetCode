class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> table;
        for (auto& p : points) {
            table[p[0]].insert(p[1]);
        }
        
        int minArea = 0;
        for (int j = 0; j < points.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                auto& p1 = points[i];
                if (p1[0] == points[j][0] || p1[1] == points[j][1]) {
                    continue;
                }
                if (table[p1[0]].count(points[j][1]) && table[points[j][0]].count(p1[1])) {
                    int area = abs((points[j][0] - p1[0]) * (points[j][1] - p1[1]));
                    if (minArea == 0 || area < minArea) {
                        minArea = area;
                    }
                }
            }
        }
        return minArea;
    }
};
