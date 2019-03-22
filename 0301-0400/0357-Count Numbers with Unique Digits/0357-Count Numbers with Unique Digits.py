class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        count = 1
        base = 9
        product = 9
        for i in range(1, min(n+1, 11)):
            count += product
            product *= base
            base -= 1
        return count
