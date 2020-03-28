class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0 || nums[i] != nums[count - 1]) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
