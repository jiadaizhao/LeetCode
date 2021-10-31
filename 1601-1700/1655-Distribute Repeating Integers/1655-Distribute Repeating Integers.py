import collections
class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:
        count = list(collections.Counter(nums).values())
        quantity.sort(reverse=True)
        def dfs(start):
            if start == len(quantity):
                return True
            itemSize = quantity[start]
            for i, c in enumerate(count):
                if c < itemSize:
                    continue
                count[i] -= itemSize
                if dfs(start + 1):
                    return True
                count[i] += itemSize
            return False
        return dfs(0)
