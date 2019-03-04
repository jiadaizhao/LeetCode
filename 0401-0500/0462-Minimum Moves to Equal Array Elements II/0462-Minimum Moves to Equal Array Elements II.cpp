class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        nth_element(nums.begin(), nums.begin() + (n - 1) / 2, nums.end());
        int mid = nums[(n - 1) / 2];
        int sum = 0;
        for (int num : nums) {
            sum += abs(num - mid);
        }
        
        return sum;
    }
};
