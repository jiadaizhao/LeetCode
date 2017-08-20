class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return nums[0];
        }

        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }

private:
    int rob(vector<int>& nums, int start, int end) {
        int dp0 = 0, dp1 = 0;
        for (int i = start; i <= end; ++i)
        {
            int dp2 = max(dp1, dp0 + nums[i]);
            dp0 = dp1;
            dp1 = dp2;
        }
        
        return dp1;
    }
};
