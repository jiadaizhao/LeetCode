class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int total = 0, change = 0;
        int min1 = INT_MAX, max1 = INT_MIN;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int curr = abs(nums[i] - nums[i + 1]);
            total += curr;
            change = max(change, abs(nums[0] - nums[i + 1]) - curr);
            change = max(change, abs(nums.back() - nums[i]) - curr);
            min1 = min(min1, max(nums[i], nums[i + 1]));
            max1 = max(max1, min(nums[i], nums[i + 1]));
        }
        
        return total + max(change, (max1 - min1) * 2);
    }
};
