class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> es(n);
        for (int i = 0; i < n; ++i) {
            es[i] = {efficiency[i], speed[i]};
        }
        sort(es.begin(), es.end(), greater<vector<int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        int MOD = 1e9 + 7;
        long maxP = 0, currSum = 0;
        for (int i = 0; i < k; ++i) {
            pq.push(es[i][1]);
            currSum += es[i][1];
            maxP = max(maxP, currSum * es[i][0]);
        }
        
        for (int i = k; i < n; ++i) {
            if (es[i][1] > pq.top()) {
                pq.push(es[i][1]);
                currSum += es[i][1] - pq.top();
                pq.pop();
                maxP = max(maxP, currSum * es[i][0]);
            }
        }
        
        return maxP % MOD;
    }
};
