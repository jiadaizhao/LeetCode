class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        vector<int> result(2);
        for (int i = 0; i < nums.size(); ++i) {
            if (table.find(target - nums[i]) != table.end()) {
                result[0] = table[target - nums[i]];
                result[1] = i;
                break;
            }
            else {
                table[nums[i]] = i;
            }
        }
        
        return result;
    }
};
