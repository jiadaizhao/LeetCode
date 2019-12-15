class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int block : blocks) {
            pq.push(block);
        }
        while (pq.size() > 1) {
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(y + split);
        }
        
        return pq.top();
    }
};
