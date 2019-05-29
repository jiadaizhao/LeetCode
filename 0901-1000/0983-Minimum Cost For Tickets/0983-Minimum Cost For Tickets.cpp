class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> table(days.begin(), days.end());
        vector<int> dp(1 + days.back());
        for (int i = 1; i < dp.size(); ++i) {
            if (table.count(i)) {
                dp[i] = min({dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        return dp.back();
    }
};
