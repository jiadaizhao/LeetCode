class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    start = mid + 2;
                }
                else {
                    end = mid;
                }
            }
            else {
                if (nums[mid - 1] == nums[mid]) {
                    start = mid + 1;
                }
                else {
                    end = mid;
                }
            }
        }
        
        if (start % 2) {
            return nums[end];
        }
        else {
            return nums[start];
        }
    }
};
