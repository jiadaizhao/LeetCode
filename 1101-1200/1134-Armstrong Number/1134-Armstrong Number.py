class Solution:
    def isArmstrong(self, N: int) -> bool:
        digit = []
        num = N
        while num:
            digit.append(num % 10)
            num //= 10
        return sum(d ** len(digit) for d in digit) == N
