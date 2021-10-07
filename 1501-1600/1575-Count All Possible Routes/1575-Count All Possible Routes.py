from functools import lru_cache
class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        MOD = 10 ** 9 + 7
        @lru_cache(None)
        def dfs(curr, fuel):
            if fuel < 0:
                return 0
            result = 1 if curr == finish else 0
            for next, location in enumerate(locations):
                if next != curr:
                    result = (result + dfs(next, fuel - abs(locations[curr] - location))) % MOD
            return result
        return dfs(start, fuel)
