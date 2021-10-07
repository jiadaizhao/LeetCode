class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        xs = sorted(x for x, y in points)
        return max(xs[i] - xs[i - 1] for i in range(1, len(xs)))
