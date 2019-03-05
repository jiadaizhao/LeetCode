class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() <= 3) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int sum1 = nums[i] + nums[j];
                int t = target - sum1;
                int start = j + 1, end = nums.size() - 1;
                while (start < end) {
                    int sum = nums[start] + nums[end];
                    if (sum < t) {
                        ++start;
                    }
                    else if (sum > t) {
                        --end;
                    }
                    else {
                        result.push_back({nums[i], nums[j], nums[start], nums[end]});
                        
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
        }
        
        return result;
    }
};
