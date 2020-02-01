from functools import reduce, lru_cache
class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        key = reduce(lambda x, y : 10 * x + y, needs)
        base = [10 ** (len(price) - 1 - i) for i in range(len(price))]
        @lru_cache(None)
        def dfs(key):
            total = 0
            curr = [key // base[i] % 10 for i in range(len(price))]
            for i in range(len(price)):
                total += curr[i] * price[i]
                
            for s in special:
                nextKey = 0
                for i in range(len(price)):
                    if curr[i] >= s[i]:
                        nextKey = nextKey * 10 + curr[i] - s[i]
                    else:
                        break
                else:
                    total = min(total, s[-1] + dfs(nextKey))
            return total
        return dfs(key)
