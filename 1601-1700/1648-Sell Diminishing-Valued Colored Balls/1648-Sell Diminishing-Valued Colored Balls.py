class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        inventory.sort(reverse=True)
        n = len(inventory)
        curr = inventory[0]
        w = 0
        MOD = 10 ** 9 + 7
        result = 0
        while orders > 0:
            while w < n and inventory[w] == curr:
                w += 1
            next = 0 if w == n else inventory[w]
            h = curr - next
            if orders < w * h:
                count = orders
                h = orders // w
                rem = orders % w
            else:
                count = w * h
                rem = 0
            val = curr - h
            result = (result + (val + 1 + curr) * h // 2 * w + val * rem) % MOD
            orders -= count
            curr = next
        return result
