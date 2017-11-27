class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <= 2) {
            int sum = 0;
            for (int num : nums) {
                sum += num;
            }
            
            return sum;
        }
        
        int closestSum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int start = i + 1, end = nums.size() - 1;
            int t = target - nums[i];
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum == t) {
                    return target;
                }
                else if (sum < t) {
                    if (t - sum < abs(target - closestSum)) {
                        closestSum = nums[i] + sum;
                    }
                    ++start;
                }
                else {
                    if (sum - t < abs(target - closestSum)) {
                        closestSum = nums[i] + sum;
                    }
                    --end;
                }
            }
        }
        
        return closestSum;
    }
};
