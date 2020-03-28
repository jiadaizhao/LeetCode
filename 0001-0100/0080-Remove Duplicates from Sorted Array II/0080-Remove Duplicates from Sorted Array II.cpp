class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if (count < 2 || num > nums[count - 2]) {
                nums[count++] = num;
            }
        }
        return count;
    }
};
