class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return false;
        }
        
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return true;
            }
            
            if (nums[mid] < nums[end]) {
                if (nums[mid] < target && nums[end] >= target) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
            else if (nums[start] < nums[mid]) {
                if (nums[start] <= target && nums[mid] > target) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else if (nums[start] == nums[mid]) {
                ++start;
            }
            else {
                --end;
            }
        }
        
        return nums[start] == target || nums[end] == target;
    }
};
