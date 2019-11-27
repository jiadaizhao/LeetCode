class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        count = 1
        i = 2
        left =  N - i * (i - 1) // 2
        while left > 0:
            if left % i == 0:
                count += 1
            i += 1
            left = N - i * (i - 1) // 2

        return count
