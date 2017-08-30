class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
        {
            return false;
        }
        
        int count = 1;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[count - 1])
            {
                nums[count] = nums[i];
                ++count;
                if (count == 3)
                {
                    return true;
                }
            }
            else if (count == 1 || nums[i] <= nums[0])
            {
                nums[0] = nums[i];
            }
            else
            {
                nums[1] = nums[i];
            }
        }
        
        return false;
    }
};
