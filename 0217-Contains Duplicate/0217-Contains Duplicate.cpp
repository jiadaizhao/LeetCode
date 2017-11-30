class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> table;
        for (int num : nums) {
            if (++table[num] > 1) {
                return true;
            }
        }
        
        return false;
    }
};
