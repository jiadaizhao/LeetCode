class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int missing = nums.back() - nums[0] + 1 - nums.size();
        if (missing < k) {
            return nums.back() + k - missing;
        }
        
        int low = 0, high = nums.size();
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            int missing = nums[mid] - nums[low] - (mid - low);
            if (missing < k) {
                k -= missing;
                low = mid;
            }
            else {
                high = mid;
            }
        }
        return  nums[low] + k;
    }
};
