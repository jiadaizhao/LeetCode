class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> presum(101);
        for (int num : nums) {
            ++presum[num];
        }
        for (int i = 1; i <= 100; ++i) {
            presum[i] += presum[i - 1];
        }
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result[i] = presum[nums[i] - 1];
            }
        }
        return result;
    }
};
