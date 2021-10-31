import math
import itertools
class Solution:
    def minimumIncompatibility(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if k == n:
            return 0
        dp = [[math.inf] * n for _ in range(1 << n)] 
        nums.sort()
        for i in range(n):
            dp[1<<i][i] = 0

        for mask in range(1<<n):
            n_z_bits = [j for j in range(n) if mask & (1 << j)]
            if len(n_z_bits) % (n // k) == 1:
                for j, l in itertools.permutations(n_z_bits, 2):
                    dp[mask][l] = min(dp[mask][l], dp[mask ^ (1 << l)][j])
            else:
                for j, l in itertools.combinations(n_z_bits, 2):
                    if nums[j] != nums[l]:
                        dp[mask][j] = min(dp[mask][j], dp[mask ^ (1 << j)][l] + nums[l] - nums[j])
                        
        return min(dp[-1]) if min(dp[-1]) != math.inf else -1
