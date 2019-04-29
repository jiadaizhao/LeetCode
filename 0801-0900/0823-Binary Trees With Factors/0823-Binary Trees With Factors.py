class Solution:
    def numFactoredBinaryTrees(self, A: List[int]) -> int:
        MOD = 1000000007
        A.sort()
        table = {x: i for i, x in enumerate(A)}
        dp = [1] * len(A)
        total = 0
        for i in range(len(A)):
            for j in range(i):
                if A[i] % A[j] == 0:
                    num = A[i] // A[j]
                    if num in table:
                        dp[i] = (dp[i] + dp[j] * dp[table[num]]) % MOD
            total = (total + dp[i]) % MOD
        return total
