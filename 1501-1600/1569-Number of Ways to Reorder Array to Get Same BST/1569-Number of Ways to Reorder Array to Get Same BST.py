import math
class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        MOD = 10 ** 9 + 7
        def dfs(nums):
            n = len(nums)
            if n <= 2:
                return 1
            left = [num for num in nums if num < nums[0]]
            right = [num for num in nums if num > nums[0]]
            leftResult = dfs(left)
            rightResult = dfs(right)
            return math.comb(n - 1, len(left)) * leftResult * rightResult % MOD
        return (dfs(nums) - 1) % MOD
