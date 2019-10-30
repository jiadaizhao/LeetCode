class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs(startTime.size());
        for (int i = 0; i < startTime.size(); ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](vector<int>& v1, vector<int>& v2){return v1[1] < v2[1];});
        vector<vector<int>> dp = {{0, 0}};
        for (auto job : jobs) {
            auto it = lower_bound(dp.begin(), dp.end(), vector<int>{job[0] + 1, 0});
            --it;
            int currMaxProfit = (*it)[1] + job[2];
            if (currMaxProfit > dp.back()[1]) {
                dp.push_back({job[1], currMaxProfit});
            }
        }

        return dp.back()[1];
    }
};
