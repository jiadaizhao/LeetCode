class Solution:
    def confusingNumber(self, N: int) -> bool:
        table = {0:0, 1:1, 6:9, 8:8, 9:6}
        num = 0
        n = N
        while n:
            curr = n % 10
            if curr not in table:
                return False
            num = num * 10 + table[curr]
            n //= 10
        return num != N
