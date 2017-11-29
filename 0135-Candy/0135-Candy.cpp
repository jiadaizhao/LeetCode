class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) {
            return 0;
        }
        vector<int> nums(n);
        nums[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                nums[i] = nums[i - 1] + 1;
            }
            else {
                nums[i] = 1;
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                nums[i] = max(nums[i], nums[i + 1] + 1);
            }
        }
        
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
