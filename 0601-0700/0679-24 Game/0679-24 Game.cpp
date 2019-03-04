class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        int used = 0;
        for (int bit = 0; bit < 4; ++bit) {
            if (dfs(nums, 1 << bit, nums[bit], 24)) {
                return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<int>& nums, int used, double curr, double target) {
        if (used == 15) {
            return abs(curr - target) < 0.001;
        }

        for (int bit = 0; bit < 4; ++bit) {
            int mask = 1 << bit;
            if ((used & mask) == 0) {
                used |= mask;
                if (dfs(nums, used, curr + nums[bit], target) || dfs(nums, used, curr - nums[bit], target) ||
                    dfs(nums, used, nums[bit] - curr, target) || dfs(nums, used, curr * nums[bit], target) ||
                    dfs(nums, used, curr / nums[bit], target)) {
                    return true;
                }
                
                if (curr != 0 && dfs(nums, used, nums[bit] / curr, target)) {
                    return true;
                }
                
                if (dfs(nums, used, nums[bit], target - curr) || dfs(nums, used, nums[bit], curr - target) ||
                    dfs(nums, used, nums[bit], target + curr)) {
                    return true;
                }
                
                if (curr != 0 && (dfs(nums, used, nums[bit], target / curr) ||
                                  dfs(nums, used, nums[bit], target * curr))) {
                    return true;
                }
                
                if (target != 0 && curr != 0 && dfs(nums, used, nums[bit], curr / target)) {
                    return true;
                }

                used &= ~mask;
            }
        }
        return false;
    }
};
