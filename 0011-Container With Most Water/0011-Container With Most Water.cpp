class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int start = 0, end = height.size() - 1;
        while (start < end)
        {
            maxA = max(maxA, min(height[start], height[end]) * (end -start));
            if (height[start] <= height[end])
            {
                ++start;
            }
            else
            {
                --end;
            }
        }
        
        return maxA;
    }
};
