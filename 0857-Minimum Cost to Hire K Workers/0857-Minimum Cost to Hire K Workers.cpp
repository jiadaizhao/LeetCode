class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double minCost = INT_MAX;
        int n = quality.size();
        vector<pair<double, int>> ratioAndQuality(n);
        for (int i = 0; i < n; ++i) {
            ratioAndQuality[i] = {(double)wage[i] / quality[i], quality[i]};
        }
        sort(ratioAndQuality.begin(), ratioAndQuality.end());
        priority_queue<int> pq;
        int sum = 0;
        for (auto rq : ratioAndQuality) {
            sum += rq.second;
            pq.push(rq.second);
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                minCost = min(minCost, sum * rq.first);
            }
        }
        return minCost;
    }
};
