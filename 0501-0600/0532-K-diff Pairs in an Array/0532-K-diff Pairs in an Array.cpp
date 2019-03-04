// Two pointers
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while (i < n) {
            while ((j <= i) || (j < n && nums[j] - nums[i] < k)) {
                ++j;
            }
            
            if (j < n && nums[j] - nums[i] == k) {
                ++count;
            }
            
            int temp = nums[i];
            while (i < n && nums[i] == temp) {
                ++i;
            }
        }
        
        return count;
    }
};

// Hash table
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k < 0) {
            return 0;
        }
        int count = 0;
        unordered_map<int, int> table;
        for (int num : nums) {
            ++table[num];
        }
        
        for (auto it = table.begin(); it != table.end(); ++it) {
            if (k == 0) {
                if (it->second > 1) {
                    ++count;
                }
            }
            else if (table.find(it->first + k) != table.end()) {
                ++count;
            }
        }
        
        return count;
    }
};
