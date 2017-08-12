class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
        {
            return;
        }
        
        int i;
        for (i = n - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                int j = n - 1;
                while (nums[j] <= nums[i])
                {
                    --j;
                }
                swap(nums[i], nums[j]);
                break;
            }
        }
        
        reverse(nums.begin() + i + 1, nums.end());
    }
};
