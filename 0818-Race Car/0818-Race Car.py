class Solution:
    def racecar(self, target):
        memo = {}
        def dfs(target):
            if target in memo:
                return memo[target]
            n = target.bit_length()
            if 2**n - 1 == target:
                memo[target] = n
            else:
                memo[target] = dfs(2 ** n - 1 - target) + n + 1
                for m in range(n - 1):
                    memo[target] = min(memo[target], dfs(target - 2 ** (n - 1) + 2 ** m) + n + m + 1)
            return memo[target]
        return dfs(target)

sol = Solution()
target = 5478
result = sol.racecar(target)
print(result)