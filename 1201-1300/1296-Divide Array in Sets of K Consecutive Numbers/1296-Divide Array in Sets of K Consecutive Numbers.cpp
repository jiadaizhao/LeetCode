class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k) {
            return false;
        }
        
        map<int, int> table;
        for (int num : nums) {
            ++table[num];
        }
        
        for (auto p : table) {
            if (p.second > 0) {
                int need = p.second;
                for (int i = p.first; i < p.first + k; ++i) {
                    if (table[i] < need) {
                        return false;
                    }
                    table[i] -= need;
                }
            }
        }
        
        return true;
    }
};
