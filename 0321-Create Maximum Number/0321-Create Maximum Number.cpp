class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> result(k);
        for (int i = max(k - n, 0); i <= min(m, k); ++i)
        {
            vector<int> left = reserveKdigits(nums1, i);
            vector<int> right = reserveKdigits(nums2, k - i);
            result = max(result, merge(left, right));
        }
        
        return result;
    }
    
private:
    vector<int> reserveKdigits(vector<int>& nums, int k) {
        vector<int> result;
        if (k == 0)
        {
            return result;
        }
        
        int count = nums.size() - k;
        for (int num : nums)
        {
            while (!result.empty() && num > result.back() && count)
            {
                result.pop_back();
                --count;
            }
            result.push_back(num);
        }
        
        result.resize(k);
        return result;
    }
    
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> result(m + n);
        int i = 0, j = 0;
        for (int k = 0; k < m + n; ++k)
        {
            result[k] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        
        return result;
    }
    
    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        int m = nums1.size();
        int n = nums2.size();
        while (i < m && j < n && nums1[i] == nums2[j])
        {
            ++i;
            ++j;
        }
        
        return j == n || (i < m && nums1[i] > nums2[j]);
    }
};
