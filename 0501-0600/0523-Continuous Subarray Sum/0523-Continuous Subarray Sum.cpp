class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int presum = 0;
        unordered_map<int, int> table;
        table[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            presum += nums[i];
            int target = (k == 0) ? presum : presum % k;
            if (table.find(target) != table.end()) {
                if (i - table[target] > 1) {
                    return true;
                }
            }
            else {
                table[target] = i;
            }
        }
        
        return false;
    }
};
