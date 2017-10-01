class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxLen = 1;
        int totalCount = 1; 
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (nums[j] > nums[i]) {
                    if (1 + dp[i] > dp[j]) {
                        dp[j] = 1 + dp[i];
                        count[j] = count[i];
                    }
                    else if (1 + dp[i] == dp[j]) {
                        count[j] += count[i];
                    }                    
                }
            }
            
            if (dp[j] > maxLen) {
                maxLen = dp[j];
                totalCount = count[j];                
            }
            else if (dp[j] == maxLen) {
                totalCount += count[j];
            }
        }

        return totalCount;
    }
};
