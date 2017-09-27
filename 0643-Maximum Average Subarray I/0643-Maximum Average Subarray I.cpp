class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int sum = 0;
        while (i < k)
        {
            sum += nums[i++];
        }
        
        int maxSum = sum;
        while (i < n)
        {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
            ++i;
        }
        
        return (double)maxSum / k;
    }
};
