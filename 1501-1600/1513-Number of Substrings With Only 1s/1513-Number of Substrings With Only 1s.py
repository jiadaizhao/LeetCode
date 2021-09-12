class Solution:
    def numSub(self, s: str) -> int:
        curr = total = 0
        MOD = 10 ** 9 + 7
        for c in s:
            if c == '1':
                curr += 1
                total = (total + curr) % MOD
            else:
                curr = 0
        return total
