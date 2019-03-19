class Solution:
    _dp = [0]
    def numSquares(self, n: int) -> int:
        dp = self._dp
        while len(dp) <= n:
            j = 1
            result = len(dp)
            while j * j <= len(dp):
                result = min(result, 1 + dp[-j*j])
                j += 1
            dp.append(result)
        return dp[n]

import math
class Solution2:
    def numSquares(self, n: int) -> int:
        root = int(math.sqrt(n))
        if root*root == n:
            return 1
        
        while n % 4 == 0:
            n //= 4
            
        if n % 8 == 7:
            return 4
        
        root = int(math.sqrt(n))
        for i in range(1, root + 1):
            val = n - i*i
            temp = int(math.sqrt(val))
            if temp*temp == val:
                return 2
        return 3
