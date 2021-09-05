class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> table;
        int start = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            table.insert(nums[i]);
            while (*table.rbegin() - *table.begin() > limit) {
                table.erase(table.find(nums[start++]));
            }
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};

