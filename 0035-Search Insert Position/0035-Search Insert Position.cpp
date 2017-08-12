class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid; 
            }
            else
            {
                return mid;
            }
        }
        
        if (target > nums[end])
        {
            return end + 1;
        }
        else if (target <= nums[start])
        {
            return start;
        }
        else
        {
            return end;
        }
    }
};
