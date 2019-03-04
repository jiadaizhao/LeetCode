class Solution:
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        total = sum(map(max, grid))
        total += sum(map(max, zip(*grid)))
        total += sum(x > 0 for row in grid for x in row)
        return total
