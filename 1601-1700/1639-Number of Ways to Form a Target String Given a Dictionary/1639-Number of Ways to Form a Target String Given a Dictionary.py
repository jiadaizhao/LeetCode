from functools import lru_cache
class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 10 ** 9 + 7
        table = [[0] * len(words[0]) for _ in range(26)]
        for word in words:
            for i, c in enumerate(word):
                table[ord(c) - ord('a')][i] += 1

        @lru_cache(None)
        def dfs(start, wi):
            if start == len(target):
                return 1
            if wi == len(words[0]):
                return 0
            
            result = dfs(start, wi + 1)
            c = target[start]
            if table[ord(c) - ord('a')][wi] > 0:
                result = (result + dfs(start + 1, wi + 1) * table[ord(c) - ord('a')][wi]) % MOD
            return result
        return dfs(0, 0)
