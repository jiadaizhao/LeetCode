class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return;
        }
        bool down = false;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if ((down && nums[i] < nums[i + 1]) || (!down && nums[i] > nums[i + 1]))
            {
                swap(nums[i], nums[i + 1]);
            }
            down = !down;
        }
    }
};
