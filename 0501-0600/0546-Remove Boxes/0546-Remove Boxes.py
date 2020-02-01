from functools import lru_cache
class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        @lru_cache(None)
        def dfs(i, j, k):
            if i > j:
                return 0

            while i < j and boxes[i] == boxes[i + 1]:
                i += 1
                k += 1
            maxVal = dfs(i + 1, j, 0) + (k + 1) * (k + 1)
            for r in range(i + 2, j + 1):
                if boxes[i] == boxes[r]:
                    maxVal = max(maxVal, dfs(i + 1, r - 1, 0) + dfs(r, j, k + 1))

            return maxVal
            
        return dfs(0, len(boxes) - 1, 0)
