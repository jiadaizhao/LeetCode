class Solution:
    def atMostNGivenDigitSet(self, D: List[str], N: int) -> int:
        s = str(N)
        # dp[i] means number with length i from right to left
        dp = [0] * (len(s) + 1)
        dp[0] = 1
        for i in range(1, len(s) + 1):
            for j in range(len(D) - 1, -1, -1):
                if D[j] == s[-i]:
                    dp[i] = dp[i - 1] + j * (len(D) ** (i - 1))
                    break
                elif D[j] < s[-i]:
                    dp[i] = (j + 1) * (len(D) ** (i - 1))
                    break
        
        return dp[-1] + sum(len(D) ** i for i in range(1, len(s)))
