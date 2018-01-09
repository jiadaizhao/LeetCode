class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        
        int max1 = 0, max2 = 1;
        if (nums[1] > nums[0]) {
            max1 = 1;
            max2 = 0;
        }
        
        for (int i = 2; i < n; ++i) {
            if (nums[i] > nums[max1]) {
                max2 = max1;
                max1 = i;
            }
            else if (nums[i] > nums[max2]) {
                max2 = i;
            }
        }
        
        return nums[max1] >= nums[max2] * 2 ? max1 : -1;
    }
};
