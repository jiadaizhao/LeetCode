class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        K -= 1
        count = 0
        while K:
            count += 1
            K &= K - 1
        return count & 1
