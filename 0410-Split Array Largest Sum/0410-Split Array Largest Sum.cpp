class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int start = nums[0], end = 0;
        for (int num : nums)
        {
            start = max(start, num);
            end += num;
        }
        
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (doable(nums, mid, m))
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        
        if (doable(nums, start, m))
        {
            return start;
        }
        else
        {
            return end;
        }
    }
    
private:
    bool doable(vector<int>& nums, int target, int m)
    {
        int sum = 0;
        int count = 1;
        for (int num : nums)
        {
            if (sum + num > target)
            {
                sum = num;
                if (++count > m)
                {
                    return false;
                }
            }
            else
            {
                sum += num;
            }
        }
        
        return true;
    }
};
