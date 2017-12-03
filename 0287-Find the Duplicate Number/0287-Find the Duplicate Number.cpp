class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n > 1) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            
            int slow2 = 0;
            while (slow != slow2) {
                slow = nums[slow];
                slow2 = nums[slow2];
            }
            
            return slow;
        }
        
        return -1;
    }
};
