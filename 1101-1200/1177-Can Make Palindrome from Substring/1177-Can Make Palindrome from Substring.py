class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        odds = [0] * (1 + len(s))
        for i, c in enumerate(s):
            odds[i + 1] = odds[i] ^ (1 << (ord(c) - ord('a')))
            
        return [bin(odds[right + 1] ^ odds[left]).count('1') // 2 <= k for left, right, k in queries]
