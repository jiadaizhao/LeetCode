class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        total = maxCost = result = 0
        for i, c in enumerate(s):
            if i > 0 and c != s[i - 1]:
                result += total - maxCost
                total = maxCost = 0
            maxCost = max(maxCost, cost[i])
            total += cost[i]
        result += total - maxCost
        return result
