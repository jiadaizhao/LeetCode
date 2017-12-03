class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0;
        long miss = 1;
        int i = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            }
            else {
                miss <<= 1;
                ++count;
            }
        }
        
        return count;
    }
};
