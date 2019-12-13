class Solution:
    def sumOfDigits(self, A: List[int]) -> int:
        num = min(A)
        s = 0
        while num:
            s += num % 10
            num //= 10
        return (s & 1) ^ 1
