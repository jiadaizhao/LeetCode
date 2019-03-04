class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int minSize = n + 1;
        int j = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && sum < s) {
                sum += nums[j];
                ++j;
            }
            
            if (sum >= s) {
                minSize = min(minSize, j - i);
            }
            
            sum -= nums[i];
        }
        
        if (minSize == n + 1) {
            return 0;
        }
        else {
            return minSize;
        }
    }
};
