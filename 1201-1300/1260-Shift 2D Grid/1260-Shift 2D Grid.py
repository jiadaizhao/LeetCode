class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        nums = sum(grid, [])
        k %= len(nums)
        nums = nums[-k:] + nums[:-k]
        col = len(grid[0])
        return [nums[i:i + col] for i in range(0, len(nums), col)]
