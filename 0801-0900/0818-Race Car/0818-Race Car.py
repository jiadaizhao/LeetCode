class Solution:
    def racecar(self, target: int) -> int:
        memo = {}
        def dfs(target):
            if target not in memo:
                n = target.bit_length()
                if (1 << n) - 1 == target:
                    result = n
                else:
                    result = dfs((1 << n) - 1 - target) + n + 1
                    for m in range(n - 1):
                        result = min(result, dfs(target - (1 << (n - 1)) + (1 << m)) + n + m + 1)
                memo[target] = result
            return memo[target]
        
        return dfs(target)
