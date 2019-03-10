class Solution:
    def climbStairs(self, n: int) -> int:
        dp0 = dp1 = 1
        for i in range(n - 1):
            dp2 = dp1 + dp0
            dp0 = dp1
            dp1 = dp2
        return dp1

class Solution2:
    def climbStairs(self, n: int) -> int:
        base = [[1, 1], [1, 0]]
        def multiply(a, b):
            c = [[0, 0], [0, 0]]
            for i in range(2):
                for j in range(2):
                    c[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j]
            return c
        
        def pow(a, n):
            result = [[1, 0], [0, 1]]
            while n > 0:
                if n&1:
                    result = multiply(result, a)
                n >>= 1
                a = multiply(a, a)
            return result
        return pow(base, n)[0][0]
