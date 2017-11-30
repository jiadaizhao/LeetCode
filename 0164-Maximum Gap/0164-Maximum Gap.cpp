class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        
        int maxI = *max_element(nums.begin(), nums.end());
        int minI = *min_element(nums.begin(), nums.end());
        
        int gap = (maxI - minI - 1) / (n - 1) + 1;
        vector<int> bucketMin(n - 1, INT_MAX);
        vector<int> bucketMax(n - 1, INT_MIN);
        
        int maxGap = 0;
        for (int i : nums) {
            if (i == minI || i == maxI) {
                continue;
            }
            
            int index = (i - minI) / gap;
            bucketMin[index] = min(bucketMin[index], i);
            bucketMax[index] = max(bucketMax[index], i);
        }
        
        int previous = minI;
        for (int i = 0; i < n - 1; ++i) {
            if (bucketMin[i] == INT_MAX) {
                continue;
            }
            
            maxGap = max(maxGap, bucketMin[i] - previous);
            previous = bucketMax[i];
        }
        
        return max(maxGap, maxI - previous);
    }
};
