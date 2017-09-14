class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        multiset<int> table(nums.begin(), nums.begin() + k);
        auto mid = next(table.begin(), (k - 1) / 2);
        if (k % 2)
        {
            result.push_back(*mid);
        }
        else
        {
            result.push_back(((double)*mid + *next(mid)) / 2);
        }
        int i = k;
        while (i < nums.size())
        {
            table.insert(nums[i]);
            
            if (nums[i] < *mid)
            {
                --mid;
            }
            
            if (nums[i - k] <= *mid)
            {
                ++mid;
            }
            
            table.erase(table.lower_bound(nums[i - k]));
            if (k % 2)
            {
                result.push_back(*mid);
            }
            else
            {
                result.push_back(((double)*mid + *next(mid)) / 2);
            }
            ++i;
        }
        
        return result;
    }
};
