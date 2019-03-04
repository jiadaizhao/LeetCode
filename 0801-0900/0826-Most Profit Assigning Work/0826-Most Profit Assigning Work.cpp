class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = profit.size();
        vector<pair<int, int>> jobs(m);
        for (int i = 0; i < m; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int total = 0, i = 0, maxProfit = 0;
        for (int j = 0; j < worker.size(); ++j) {
            while (i < m && jobs[i].first <= worker[j]) {
                maxProfit = max(maxProfit, jobs[i].second);
                ++i;
            }
            total += maxProfit;
        }
        
        return total;
    }
};
