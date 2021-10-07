class Solution:
    def numWays(self, s: str) -> int:
        total = s.count('1')
        MOD = 10 ** 9 + 7
        if total == 0:
            return (len(s) - 1) * (len(s) - 2) // 2 % MOD
        if total % 3:
            return 0
        num = total // 3
        count = 0        
        firstEnd = secondStart = secondEnd = thirdStart = -1
        for i, c in enumerate(s):
            if c == '1':
                count += 1
                if count == num:
                    firstEnd = i
                elif count == num + 1:
                    secondStart = i
                if count == num * 2:
                    secondEnd = i
                elif count == num * 2 + 1:
                    thirdStart = i
        return (secondStart - firstEnd) * (thirdStart - secondEnd) % MOD
