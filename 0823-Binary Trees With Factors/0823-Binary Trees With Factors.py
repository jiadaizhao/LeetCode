class Solution:
    def numFactoredBinaryTrees(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        MOD = 1000000007
        n = len(A)
        A.sort()
        table = {x: i for i, x in enumerate(A)}
        dp = [1] * n
        total = 0
        for i in range(n):
            for j in range(i):
                if A[i] % A[j] == 0:
                    num = A[i] / A[j]
                    if num in table:
                        dp[i] += dp[j] * dp[table[num]]
            total += dp[i]
        return total % MOD
