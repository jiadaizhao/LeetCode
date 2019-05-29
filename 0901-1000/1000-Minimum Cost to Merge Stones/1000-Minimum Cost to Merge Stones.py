from functools import lru_cache
import math
class Solution:
    def mergeStones(self, stones, K: int) -> int:
        if (len(stones) - 1) % (K - 1):
            return -1
        presum = [0] * (1 + len(stones))
        for i in range(len(stones)):
            presum[i + 1] = presum[i] + stones[i]

        @lru_cache(None)
        def dfs(start, end, p):
            if end - start + 1 == p:
                return 0

            if p == 1:
                return dfs(start, end, K) + presum[end + 1] - presum[start]

            return min(dfs(start, mid, 1) + dfs(mid + 1, end, p - 1) for mid in range(start, end, K - 1))

        return  dfs(0, len(stones) - 1, 1)


class Solution2:
    def mergeStones(self, stones, K: int) -> int:
        if (len(stones) - 1) % (K - 1):
            return -1
        presum = [0] * (1 + len(stones))
        for i in range(len(stones)):
            presum[i + 1] = presum[i] + stones[i]

        dp = [[0]*len(stones) for _ in range(len(stones))]
        for l in range(K, len(stones) + 1):
            for start in range(len(stones) - l + 1):
                end = start + l - 1
                dp[start][end] = math.inf
                for mid in range(start, end, K - 1):
                    dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end])
                if (end - start) % (K - 1) == 0:
                    dp[start][end] += presum[end + 1] - presum[start]

        return dp[0][-1]
