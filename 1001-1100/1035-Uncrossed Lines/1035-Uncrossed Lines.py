class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        dp = [0] * (1 + len(B))
        for i in range(1, 1 + len(A)):
            temp = dp[:]
            for j in range(1, 1 + len(B)):
                if A[i - 1] == B[j - 1]:
                    temp[j] = dp[j - 1] + 1
                else:
                    temp[j] = max(temp[j - 1], dp[j])
            dp = temp

        return dp[-1]
