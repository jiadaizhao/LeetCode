class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        
        if (sum % 2) {
            return false;
        }
        
        int target = sum / 2;
        vector<bool> dp(1 + target);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                if (dp[j - nums[i]]) {
                    dp[j] = true;
                }
            }
        }
        
        return dp[target];
    }
};
