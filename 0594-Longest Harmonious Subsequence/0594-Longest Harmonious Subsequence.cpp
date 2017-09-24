class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxCount = 0;
        unordered_map<int, int> table;
        for (int num : nums)
        {
            int count = ++table[num];
            if (table.find(num - 1) != table.end())
            {
                maxCount = max(maxCount, count + table[num - 1]);
            }
            if (table.find(num + 1) != table.end())
            {
                maxCount = max(maxCount, count + table[num + 1]);
            }
        }
        
        return maxCount; 
    }
};
