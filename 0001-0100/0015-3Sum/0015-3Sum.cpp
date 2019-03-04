class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() <= 2) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int start = i + 1, end = nums.size() - 1;
            int target = -nums[i];
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum < target) {
                    ++start;
                }
                else if (sum > target) {
                    --end;
                }
                else {
                    vector<int> path;
                    path.push_back(nums[i]);
                    path.push_back(nums[start]);
                    path.push_back(nums[end]);
                    result.push_back(path);
                    
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
