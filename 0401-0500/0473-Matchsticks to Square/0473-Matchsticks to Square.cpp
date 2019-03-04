class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) {
            return false;
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4) {
            return false;
        }
        
        int target = sum / 4;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> sides(4);
        return dfs(nums, 0, sides, target);
    }
    
private:
    bool dfs(vector<int>& nums, int start, vector<int>& sides, int target) {
        if (start == nums.size()) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        
        for (int i = 0; i < 4; ++i) {
            if (sides[i] + nums[start] > target) {
                continue;
            }
            
            int j;
            for (j = i - 1; j >= 0; --j) {
                if (sides[i] == sides[j]) {
                    break;
                }
            }
            
            if (j != -1) {
                continue;
            }
            
            sides[i] += nums[start];
            if (dfs(nums, start + 1, sides, target)) {
                return true;
            }
            sides[i] -= nums[start];
        }
        
        return false;
    }
};
