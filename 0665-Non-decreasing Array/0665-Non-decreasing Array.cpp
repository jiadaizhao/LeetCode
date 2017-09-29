class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                ++count;
                if (count > 1)
                {
                    return false;
                }
                if (i > 1 && nums[i - 2] > nums[i] && i < n - 1 && nums[i + 1] < nums[i - 1] )
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
