class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> St;
        heights.push_back(0);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!St.empty() && heights[St.top()] >= heights[i]) {
                int h = heights[St.top()];
                St.pop();
                int w = (St.size()) ? i - St.top() - 1 : i;
                maxArea = max(maxArea, h * w);
            }
            St.push(i);
        }
        
        return maxArea;
    }
};
