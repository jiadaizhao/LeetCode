class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        vector<int> seq = {nums[0]};
        for (int i = 1; i < n; ++i) {
            if (nums[i] > seq.back()) {
                seq.push_back(nums[i]);
            }
            else {
                auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
                *it = nums[i];
            }
        }
        
        return seq.size();
    }
};
