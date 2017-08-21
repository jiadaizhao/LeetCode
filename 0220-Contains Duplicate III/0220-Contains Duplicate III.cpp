class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 0 || t < 0)
        {
            return false;
        }
        map<long, int> table;
        for (int i = 0; i < nums.size(); ++i)
        {
            long low = nums[i] - (long)t;
            long high = nums[i] + (long)t;
            auto itlow = table.lower_bound(low);
            auto ithigh = table.upper_bound(high);
            while (itlow != ithigh)
            {
                if (i - itlow->second <= k)
                {
                    return true;
                }
                ++itlow;
            }
            table[nums[i]] = i; 
        }
        
        return false;
    }
};
