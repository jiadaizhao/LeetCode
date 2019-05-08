class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        total = sum(map(max, grid))
        total += sum(map(max, zip(*grid)))
        total += sum(val > 0 for row in grid for val in row)
        return total
