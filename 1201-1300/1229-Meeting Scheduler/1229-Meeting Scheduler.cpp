class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& s : slots1) {
            if (s[1] - s[0] >= duration) {
                pq.push({s[0], s[1]});
            }
        }
        
        for (auto& s : slots2) {
            if (s[1] - s[0] >= duration) {
                pq.push({s[0], s[1]});
            }
        }
        
        while (pq.size() > 1) {
            auto p = pq.top();
            pq.pop();
            if (pq.top().first + duration <= p.second) {
                return {pq.top().first, pq.top().first + duration};
            }
        }
        return {};
    }
};
