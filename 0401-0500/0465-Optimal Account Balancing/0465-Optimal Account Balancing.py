import collections
class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        debt = collections.Counter()
        for x, y, z in transactions:
            debt[x] -= z
            debt[y] += z

        amount = [v for v in debt.values() if v]
        N = len(amount)
        dp = [0] * (1 << N) # number of sets whose sum is 0
        sums = [0] * (1 << N)
        for mask in range(1 << N):
            for curr in range(N):
                if mask & (1 << curr) == 0:
                    nmask = mask | (1 << curr)
                    sums[nmask] = sums[mask] + amount[curr]
                    if sums[nmask] == 0:
                        dp[nmask] = max(dp[nmask], dp[mask] + 1)
                    else:
                        dp[nmask] = max(dp[nmask], dp[mask])
        
        return N - dp[-1]
