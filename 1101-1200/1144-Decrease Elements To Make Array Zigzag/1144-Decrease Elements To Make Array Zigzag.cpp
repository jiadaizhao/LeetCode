class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int move1 = 0, move2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int left = (i > 0) ? nums[i - 1] - 1 : nums[i];
            int right = (i < nums.size() - 1) ? nums[i + 1] - 1 : nums[i];
            int curr = max(nums[i] - min(left, right), 0);
            if (i & 1) {
                move2 += curr;
            }
            else {
                move1 += curr;
            }
        }

        return min(move1, move2);
    }
};
