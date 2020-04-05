class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        table[0] = -1;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (table.count(sum - k)) {
                maxLen = max(maxLen, i - table[sum - k]);
            }
            if (!table.count(sum)) {                
                table[sum] = i;
            }
        }
        return maxLen;
    }
};
