class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1) {
                continue;
            }
            
            if (i == j) {
                result.push_back(to_string(nums[i]));
            }
            else {
                result.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j + 1;
        }
        
        return result;
    }
};
