class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        
        sort(nums.begin(), nums.end());
        vector<int> parent(n);
        vector<int> dp(n);
        int maxNum = 0;
        int maxIndex = -1;
        for (int j = 0; j < n; ++j) {
            for (int i = j; i >= 0; --i) {
                if (nums[j] % nums[i] == 0 && 1 + dp[i] > dp[j]) {
                    parent[j] = i;
                    dp[j] = 1 + dp[i];
                    if (dp[j] > maxNum) {
                        maxNum = dp[j];
                        maxIndex = j;
                    }
                }
            }
        }

        vector<int> result(maxNum);
        for (int i = result.size() - 1; i >= 0; --i) {
            result[i] = nums[maxIndex];
            maxIndex = parent[maxIndex];
        }
        
        return result;
    }
};
