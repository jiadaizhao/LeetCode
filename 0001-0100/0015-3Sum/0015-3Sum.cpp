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
            if (i == 0 || nums[i] != nums[i - 1]) {
                int start = i + 1, end = n - 1;
                while (start < end) {
                    if (nums[start] + nums[end] < -nums[i]) {
                        ++start;
                    }
                    else if (nums[start] + nums[end] > -nums[i]) {
                        --end;
                    }
                    else {
                        result.push_back({nums[i], nums[start], nums[end]});
                        ++start;
                        while (start < end && nums[start] == nums[start - 1]) {
                            ++start;
                        }
                        --end;
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
