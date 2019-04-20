class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {        
        int dp0 = cost[0], dp1 = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            int dp2 = min(dp0, dp1) + cost[i];
            dp0 = dp1;
            dp1 = dp2;
        }
        
        return min(dp0, dp1);        
    }
};
