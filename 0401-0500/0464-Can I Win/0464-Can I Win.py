class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if maxChoosableInteger >= desiredTotal:
            return True
        if (1 + maxChoosableInteger)*maxChoosableInteger//2 < desiredTotal:
            return False
        used = 0
        cache = {}
        def dfs(used, target):
            if target <= 0:
                return False
            if used in cache:
                return cache[used]
            
            result = False
            key = used
            for bit in range(1, maxChoosableInteger + 1):
                mask = 1 << bit
                if used & mask == 0:
                    used |= mask
                    if not dfs(used, target - bit):
                        result = True
                        break
                    used &= (~mask)
                    
            cache[key] = result
            return result
        
        return dfs(0, desiredTotal)
