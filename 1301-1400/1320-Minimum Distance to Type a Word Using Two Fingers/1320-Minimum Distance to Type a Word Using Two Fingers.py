class Solution:
    def minimumDistance(self, word: str) -> int:
        def dist(source, target):
            return abs(source // 6 - target // 6) + abs(source % 6 - target % 6)
        dp = [0] * 26
        total = 0
        for b, c in zip(word, word[1:]):
            ib = ord(b) - 65
            ic = ord(c) - 65
            orig = dist(ib, ic)
            total += orig
            dp[ib] = max(dp[ia] + orig - dist(ia, ic) for ia in range(26))            
            
        return total - max(dp)
