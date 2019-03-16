class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        while n > m:
            n &= n - 1
        return n
