class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return to_string(nums[0]);
        }
        else if (n == 2) {
            return to_string(nums[0]) + '/' + to_string(nums[1]);
        }
        
        string result = to_string(nums[0]) + "/(";
        for (int i = 1; i < n - 1; ++i) {
            result += to_string(nums[i]) + '/';
        }
        
        result += to_string(nums[n - 1]) + ')';
        return result;
    }
};
