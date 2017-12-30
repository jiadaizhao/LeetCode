class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 2) {
            return min(cost[0], cost[1]);
        }
        
        int dp0 = cost[0], dp1 = cost[1];
        int dp2;
        for (int i = 2; i < n; ++i) {
            dp2 = min(dp0, dp1) + cost[i];
            dp0 = dp1;
            dp1 = dp2;
        }
        
        return min(dp0, dp2);
        
    }
};
