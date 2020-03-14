class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMax(n), dpMin(n);
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dpMax[i] = nums[i];
            dpMin[i] = nums[i];
            if (nums[i] >= 0) {
                dpMax[i] = max(dpMax[i], dpMax[i - 1] * nums[i]);
                dpMin[i] = min(dpMin[i], dpMin[i - 1] * nums[i]);
            }
            else {
                dpMax[i] = max(dpMax[i], dpMin[i - 1] * nums[i]);
                dpMin[i] = min(dpMin[i], dpMax[i - 1] * nums[i]);
            }
        }
        
        int maxProduct = nums[0];
        for (int dpm : dpMax) {
            maxProduct = max(maxProduct, dpm);
        }
        
        return maxProduct;
    }
};

// Optimize space to O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int dpMax = nums[0], dpMin = nums[0], maxProduct = nums[0];
        for (int i = 1; i < n; ++i) {
            int tempMax = nums[i];
            int tempMin = nums[i];
            if (nums[i] >= 0) {
                tempMax = max(tempMax, dpMax * nums[i]);
                tempMin = min(tempMin, dpMin * nums[i]);
            }
            else {
                tempMax = max(tempMax, dpMin * nums[i]);
                tempMin = min(tempMin, dpMax * nums[i]);
            }
            maxProduct = max(maxProduct, tempMax);
            dpMax = tempMax;
            dpMin = tempMin;
        }
        
        return maxProduct;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dpMin = nums[0], dpMax = nums[0], maxP = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(dpMin, dpMax);
            }
            dpMax = max(nums[i], dpMax * nums[i]);
            dpMin = min(nums[i], dpMin * nums[i]);
            maxP = max(maxP, dpMax);
        }
        return maxP;
    }
};
