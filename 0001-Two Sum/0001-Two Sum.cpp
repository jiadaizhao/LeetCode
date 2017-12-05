class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> table;
        std::vector<int> result(2);
        for (auto i = 0; i < nums.size(); ++i) {
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
