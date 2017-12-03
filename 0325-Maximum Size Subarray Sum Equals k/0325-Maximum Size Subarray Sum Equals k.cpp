class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        table[0] = -1;
        int maxLen = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (table.find(sum - k) != table.end()) {
                maxLen = max(maxLen, i - table[sum - k]);
            }
            if (table.find(sum) == table.end()) {
                table[sum] = i;
            }
        }
        
        return maxLen;
    }
};
