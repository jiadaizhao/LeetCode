class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> table;
        for (int i = 0; i < nums.size(); ++i) {
            long low = nums[i] - (long)t;
            auto itlow = table.lower_bound(low);
            if (itlow != table.end() && *itlow <= nums[i] + (long)t) {
                return true;
            }
            table.insert(nums[i]);
            if (i >= k) {
                table.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 0 || t < 0) {
            return false;
        }
        unordered_map<long, long> table;
        long w = t + 1LL;
        for (int i = 0; i < nums.size(); ++i) {
            long m = getID(nums[i], w);
            if (table.find(m) != table.end()) {
                return true;
            }
            if (table.find(m - 1) != table.end() && abs(nums[i] - table[m - 1]) < w) {
                return true;
            }
            if (table.find(m + 1) != table.end() && abs(nums[i] - table[m + 1]) < w) {
                return true;
            }
            table[m] = nums[i];
            if (i >= k) {
                table.erase(getID(nums[i - k], w));
            }
        }
        return false;
    }

private:
    long getID(long x, long w) {
        return x < 0 ? (x + 1) / w - 1 : x / w;
    }
};
