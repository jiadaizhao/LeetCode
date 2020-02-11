class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int n = nums.size();
        if (n == 0) {
            return result;
        }
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        if (nums[low] != target) {
            return result;
        }
        else {
            result[0] = low;
        }
        
        high = n - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid;
            }
        }
        result[1] = low;
        return result;
    }
};
