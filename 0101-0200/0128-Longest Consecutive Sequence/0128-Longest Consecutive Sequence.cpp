class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> table;
        for (int num : nums) {
            table.insert(num);
        }
        
        int maxLen = 0;
        for (int num : nums) {
            if (table.find(num) != table.end()) {
                table.erase(num);
                int len = 1;
                int i = 1;
                while (table.find(num + i) != table.end()) {
                    table.erase(num + i);
                    ++len;
                    ++i;
                }
                
                i = 1;
                while (table.find(num - i) != table.end()) {
                    table.erase(num - i);
                    ++len;
                    ++i;
                }
                
                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
        
        return maxLen;
    }
};
