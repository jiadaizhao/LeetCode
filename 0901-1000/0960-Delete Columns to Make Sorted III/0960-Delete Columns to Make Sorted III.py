class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        minDel = m = len(A[0])
        dp = [1] * m
        for j in range(m):
            for i in range(j):
                if all(A[k][i] <= A[k][j] for k in range(len(A))):
                    dp[j] = max(dp[j], dp[i] + 1)
            minDel = min(minDel, m - dp[j])
        return minDel
