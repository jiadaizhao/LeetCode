class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int maxNum = INT_MIN;
        for (int num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if (sum % k) {
            return false;
        }
        int target = sum / k;
        if (maxNum > target) {
            return false;
        }
        
        vector<bool> dp(1 << n);
        dp[0] = true;
        vector<int> sums(1 << n);
        for (int i = 0; i < dp.size(); ++i) {
            if (!dp[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                int next = i | (1 << j);
                if (next != i && !dp[next]) {
                    if (nums[j] <= target - sums[i] % target) {
                        dp[next] = true;
                        sums[next] = sums[i] + nums[j];
                    }
                    else {
                        break;
                    }
                }
            }
        }
        
        return dp.back();
    }
};

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int maxNum = INT_MIN;
        for (int num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if (sum % k) {
            return false;
        }
        int target = sum / k;
        if (maxNum > target) {
            return false;
        }
        
        vector<int> dp(1 << n);
        dp.back() = 1;
        return dfs(nums, 0, sum, dp, target) == 1;
    }
    
private:
    int dfs(vector<int>& nums, int used, int sum, vector<int>& dp, int target) {
        if (dp[used] != 0) {
            return dp[used];
        }
        
        dp[used] = -1;
        int limit = (sum - 1) % target + 1;
        for (int i = 0; i < nums.size(); ++i) {
            if ((used & (1 << i)) == 0 && nums[i] <= limit) {
                if (dfs(nums, used | (1 << i), sum - nums[i], dp, target) == 1) {
                    dp[used] = 1;
                    break;
                }
            }
        }
        
        return dp[used];
    }
};
