class Solution {
public:
    int rob(vector<int>& nums) {
        int dp0 = 0, dp1 = 0;
        for (int num : nums) {
            int dp2 = max(dp1, dp0 + num);
            dp0 = dp1;
            dp1 = dp2;
        }
        
        return dp1;
    }
};
