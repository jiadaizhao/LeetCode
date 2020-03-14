class Solution {
public:
    int jump(vector<int>& nums) {
        int maxIndex = 0, currMax = 0, count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            currMax = max(currMax, i + nums[i]);
            if (i == maxIndex) {
                ++count;
                maxIndex = currMax;
            }
        }
        
        return count;
    }
};
