class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int s : sticks) {
            pq.push(s);
        }
        
        int cost = 0;
        while (pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            cost += s1 + s2;
            pq.push(s1 + s2);
        }
        
        return cost;
    }
};
