class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); ++i) {
            pq.emplace(points[i][0]* points[i][0] + points[i][1] * points[i][1], i);
            if (pq.size() > K) {
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            int i = pq.top().second;
            result.push_back(points[i]);
            pq.pop();
        }
        return result;
    }
};
