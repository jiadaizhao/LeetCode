class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, day = 0, count = 0;
        while (!pq.empty() || i < events.size()) {
            if (pq.empty()) {
                day = events[i][0];
            }
            while (i < events.size() && events[i][0] <= day) {
                pq.push(events[i++][1]);
            }
            pq.pop();
            ++count;
            ++day;
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }
        
        return count;
    }
};
