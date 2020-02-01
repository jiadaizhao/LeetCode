class Solution:
    def numMusicPlaylists(self, N: int, L: int, K: int) -> int:
        dp = [[0]*(1 + N) for _ in range(1 + L)]
        dp[0][0] = 1
        MOD = 10 ** 9 + 7
        for i in range(1, 1 + L):
            for j in range(1, 1 + N):
                # new song
                dp[i][j] = dp[i - 1][j - 1] * (N - j + 1) % MOD
                if j > K:
                    # old song
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - K)) % MOD
        return dp[L][N]
