class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());
        vector<int> result(2);
        result[1] = nums[2] - nums[0] - 2;
        if (nums[1] - nums[0] == 1 && nums[2] - nums[1] == 1) {
            result[0] = 0;
        }
        else if (nums[1] - nums[0] <= 2 || nums[2] - nums[1] <= 2) {
            result[0] = 1;
        }
        else {
            result[0] = 2;
        }
        
        return result;
    }
};
