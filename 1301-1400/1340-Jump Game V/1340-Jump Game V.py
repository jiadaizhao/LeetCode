from functools import lru_cache
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:        
        @lru_cache(None)
        def dfs(curr):
            currJump = 1
            for next in range(curr - 1, max(0, curr - d) - 1, -1):
                if arr[curr] > arr[next]:
                    currJump = max(currJump, 1 + dfs(next))
                else:
                    break
            for next in range(curr + 1, min(len(arr) - 1, curr + d) + 1):
                if arr[curr] > arr[next]:
                    currJump = max(currJump, 1 + dfs(next))
                else:
                    break
            return currJump
        maxJ = 0
        for i in range(len(arr)):
            maxJ = max(maxJ, dfs(i))
        return maxJ
