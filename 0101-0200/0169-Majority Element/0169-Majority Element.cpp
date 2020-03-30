class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = nums[0];
        for (int num : nums) {
            if (num == candidate) {
                ++count;
            }
            else {
                if (--count == 0) {
                    candidate = num;
                    count = 1;
                }
            }
        }
        
        return candidate;
    }
};
