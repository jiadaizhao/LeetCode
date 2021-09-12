class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.sort()
        verticalCuts.sort()
        maxH = max(h2 - h1 for h1, h2 in zip([0] + horizontalCuts, horizontalCuts + [h]))
        maxV = max(v2 - v1 for v1, v2 in zip([0] + verticalCuts, verticalCuts + [w]))
        return maxH * maxV % (10 ** 9 + 7)
