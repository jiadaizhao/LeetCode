import collections
class Solution:
    def minNumberOfSemesters(self, n: int, relations: List[List[int]], k: int) -> int:
        dependency = [0] * n
        for pc, nc in relations:
            dependency[nc - 1] |= (1 << (pc - 1))
        prerequisites = [0] * (1 << n)
        for i in range(1 << n):
            for j in range(n):
                if (1 << j) & i:
                    prerequisites[i] |= dependency[j]
        
        def countBits(x):
            count = 0
            while x:
                count += 1
                x &= (x - 1)
            return count

        dp = [n + 1] * (1 << n)
        dp[0] = 0
        for i in range(1, 1 << n):
            j = i
            while j:
                if countBits(j) <= k:
                    taken = i ^ ((1 << n) - 1)
                    if (taken & prerequisites[j]) == prerequisites[j]:
                        dp[i] = min(dp[i], dp[i ^ j] + 1)
                j = (j - 1) & i

        return dp[(1 << n) - 1]
