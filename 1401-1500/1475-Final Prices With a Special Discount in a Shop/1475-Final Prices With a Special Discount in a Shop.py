class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        result = [0] * n
        St = []
        for i in range(n - 1, -1, -1):
            while St and prices[i] < St[-1]:
                St.pop()
            result[i] = prices[i] - (St[-1] if St else 0)
            St.append(prices[i])
        return result
