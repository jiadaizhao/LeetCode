class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                result.push_back(abs(nums[i]));
            }
            else
            {
                nums[index] = -nums[index];
            }
        }
        
        return result;
    }
};
