class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        MOD = 10 ** 9 + 7
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            for j in range(1, min(i, 10) + 1):
                if s[i - j] == '0':
                    continue
                num = int(s[i - j: i])                
                if 1 <= num <= k:
                    dp[i] = (dp[i] + dp[i - j]) % MOD
                else:
                    break
        
        return dp[n]
