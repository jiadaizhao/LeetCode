class Solution:
    def lenLongestFibSubseq(self, A: List[int]) -> int:
        table = {a: i for i, a in enumerate(A)}
        maxLen = 0
        dp = [[2] * len(A) for _ in range(len(A))]
        for j in range(len(A)):
            for i in range(j):
                next = A[i] + A[j]
                if next in table:
                    index = table[next]
                    if 1 + dp[i][j] > dp[j][index]:
                        dp[j][index] = 1 + dp[i][j]
                        maxLen = max(maxLen, dp[j][index])
        return maxLen
