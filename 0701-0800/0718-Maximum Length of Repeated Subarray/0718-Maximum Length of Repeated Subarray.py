class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        dp = [0] * (1 + len(B))
        maxLen = 0
        for i in range(1, 1 + len(A)):
            for j in range(len(B), 0, -1):
                if A[i - 1] == B[j - 1]:
                    dp[j] = 1 + dp[j - 1]
                    maxLen = max(maxLen, dp[j])
                else:
                    dp[j] = 0
        return maxLen
