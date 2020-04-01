class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        rows = []
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    rows.append(i)
        cols = []
        for j in range(n):
            for i in range(m):
                if grid[i][j] == 1:
                    cols.append(j)
        def getDist(nums):
            total = start = 0
            end = len(nums) - 1
            while start < end:
                total += nums[end] - nums[start]
                start += 1
                end -= 1
            return total
        
        return getDist(rows) + getDist(cols)
