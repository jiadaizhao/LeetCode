class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        N *= 2;
        count = 1
        i = 2
        while i * i <= N:
            if N % i == 0 and ((i & 1) ^ (N // i & 1)):
                count += 1
            i += 1
        return count
