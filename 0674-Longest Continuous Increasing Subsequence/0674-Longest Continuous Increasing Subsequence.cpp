class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        int maxLen = 1;
        int curr = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                ++curr;
                maxLen = max(maxLen, curr);
            }
            else
            {
                curr = 1;
            }            
        }
        
        return maxLen;
    }
};
