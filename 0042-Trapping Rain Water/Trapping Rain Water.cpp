class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
        {
            return 0;
        }
        int left = 0, right = n - 1;
        int leftHeight = height[left];
        int rightHeight = height[right];
        int sum = 0;
        while (left < right)
        {
            if (leftHeight <= rightHeight)
            {
                ++left;
                if (leftHeight > height[left])
                {
                    sum += leftHeight - height[left];
                }
                else
                {
                    leftHeight = height[left];
                }
            }
            else
            {
                --right;
                if (rightHeight > height[right])
                {
                    sum += rightHeight - height[right];
                }
                else
                {
                    rightHeight = height[right];
                }
            }
        }
        
        return sum;
    }
};
