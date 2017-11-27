class Solution {
public:
    int jump(vector<int>& nums) {
        int maxIndex = 0, currentMax = 0;
        int count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            currentMax = max(currentMax, i + nums[i]);
            if (i == maxIndex) {
                ++count;
                maxIndex = currentMax;
            }
        }
        
        return count;
    }
};
