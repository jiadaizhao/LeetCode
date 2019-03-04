class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
