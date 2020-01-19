class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int start = i + 1, end = n - 1;
            int target = -nums[i];
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum > target) {
                    --end;
                }
                else if (sum < target) {
                    ++start;
                }
                else {
                    result.push_back({nums[i], nums[start], nums[end]});
                    ++start;
                    --end;
                    while (start < end && nums[start] == nums[start - 1]) {
                        ++start;
                    }
                    while (start < end && nums[end] == nums[end + 1]) {
                        --end;
                    }
                }
            }
        }
        return result;
    }
};
