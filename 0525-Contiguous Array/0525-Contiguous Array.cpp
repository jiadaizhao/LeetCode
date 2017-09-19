class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> table;
        table[0] = -1;
        int maxLen = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i])
            {
                ++sum;
            }
            else
            {
                --sum;
            }
            if (table.find(sum) != table.end())
            {
                maxLen = max(maxLen, i - table[sum]);
            }
            else
            {
                table[sum] = i;
            }
        }
        
        return maxLen;
    }
};
