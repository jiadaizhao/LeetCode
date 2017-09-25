class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
        {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = n - 1; i >= 2; --i)
        {
            int c = nums[i];
            int left = 0, right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] <= c)
                {
                    ++left;
                }
                else
                {
                    count += right - left;
                    --right;
                }
            }
        }
        
        return count;
    }
};
