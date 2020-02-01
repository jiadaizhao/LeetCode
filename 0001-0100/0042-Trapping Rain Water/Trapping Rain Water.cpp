class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0;
        int sum = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                sum += max(0, maxLeft - height[left]);
                maxLeft = max(maxLeft, height[left]);
                ++left;
            }
            else {
                sum += max(0, maxRight - height[right]);
                maxRight = max(maxRight, height[right]);
                --right;
            }
        }
        
        return sum;
    }
};
