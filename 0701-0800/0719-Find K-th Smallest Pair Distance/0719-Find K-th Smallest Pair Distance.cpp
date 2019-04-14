class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0, left = 0;
            for (int right = 1; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mid) {
                    ++left;
                }
                count += right - left;
            }
            
            if (count >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
