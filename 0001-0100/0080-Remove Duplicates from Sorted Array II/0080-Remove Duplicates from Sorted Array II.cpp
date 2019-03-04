class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int count = 1;
        bool duplicate = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[count - 1]) {
                duplicate = false;
                nums[count++] = nums[i];
            }
            else if (!duplicate) {
                duplicate = true;
                nums[count++] = nums[i];
            }
        }
        
        return count;
    }
};
