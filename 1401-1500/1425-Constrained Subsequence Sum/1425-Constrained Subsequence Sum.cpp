class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.begin(), nums.end());
        deque<int> dq;
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (dq.size()) {
                dp[i] += dq[0];
            }
            maxSum = max(maxSum, dp[i]);
            while (dq.size() && dp[i] >= dq.back()) {
                dq.pop_back();
            }
            if (dp[i] > 0) {
                dq.push_back(dp[i]);
            }
            if (i >= k && dq.size() && dq[0] == dp[i - k]) {
                dq.pop_front();
            }            
        }
        
        return maxSum;
    }
};
