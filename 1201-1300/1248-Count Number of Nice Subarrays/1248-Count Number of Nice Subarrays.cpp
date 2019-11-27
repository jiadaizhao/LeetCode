class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> index;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1) {
                index.push_back(i);
            }
        }
        
        int total = 0, m = index.size();
        for (int i = 0; i <= m - k; ++i) {
            int j = i + k - 1;
            total += (index[i] - (i > 0 ? index[i - 1] : -1)) * ((j < m - 1 ? index[j + 1] : n) - index[j]);
        }
        
        return total;
    }
};
