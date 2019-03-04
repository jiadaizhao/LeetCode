class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> table;
        for (int& num : nums) {
            table.insert(num);
            if (table.size() > 3) {
                table.erase(table.begin());
            }
        }
        
        return table.size() == 3 ? *table.begin() : *table.rbegin();
    }
};
