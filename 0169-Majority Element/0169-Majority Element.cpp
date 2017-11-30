class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int candidate = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == candidate) {
                ++count;
            }
            else {
                --count;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        
        return candidate;
    }
};
