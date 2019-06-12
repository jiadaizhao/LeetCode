class Solution:
    def lastStoneWeightII(self, stones) -> int:
        dp = [False] * (1 + sum(stones))
        dp[0] = True
        s = 0
        for stone in stones:
            s += stone
            for i in range(s, stone - 1, -1):
                if dp[i - stone]:
                    dp[i] = True

        for i in range(s // 2, -1, -1):
            if dp[i]:
                return s - i - i

        return 0        


class Solution2:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        dp = {0}
        s = sum(stones)
        for stone in stones:
            dp |= {x + stone for x in dp}
        return min(s - x - x for x in dp if x * 2 <= s)
