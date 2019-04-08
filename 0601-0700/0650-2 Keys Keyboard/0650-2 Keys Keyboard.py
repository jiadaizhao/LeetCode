class Solution:
    def minSteps(self, n: int) -> int:
        dp = [i for i in range(1 + n)]
        dp[1] = 0
        for i in range(2, 1 + n):
            for j in range(1, i // 2 + 1):
                if i % j == 0:
                    dp[i] = min(dp[i], dp[j] + i // j)
        return dp[-1]

class Solution2:
    def minSteps(self, n: int) -> int:
        step = 0
        i = 2
        while i <= n:
            while n % i == 0:
                step += i
                n //= i
            i += 1
            
        return step
