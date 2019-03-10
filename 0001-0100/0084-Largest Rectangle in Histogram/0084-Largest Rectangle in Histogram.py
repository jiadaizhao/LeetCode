class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        maxArea = 0
        St = []
        for i, currH in enumerate(heights):
            while St and heights[St[-1]] >= currH:
                h = heights[St.pop()]
                w = i - 1 - St[-1] if St else i
                maxArea = max(maxArea, h*w)
            St.append(i)
        return maxArea
