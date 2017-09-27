class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int minNum = INT_MAX, maxNum = INT_MIN;
        for (int num : nums)
        {
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }
        double low = minNum, high = maxNum;
        while (high - low > 10e-6)
        {
            double mid = (low + high) / 2;
            if (available(nums, k, mid))
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        
        return low;
    }
    
private:
    bool available(vector<int>& nums, int k, double target)
    {
        int n = nums.size();
        double sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum += nums[i] - target;
        }
        if (sum >= 0)
        {
            return true;
        }
        double premin = 0;
        double presum = 0;
        for (int i = k; i < n; ++i)
        {
            sum += nums[i] - target;
            presum += nums[i - k] - target;
            premin = min(premin, presum);
            if (sum - premin >= 0)
            {
                return true;
            }
        }
        
        return false;
    }
};
