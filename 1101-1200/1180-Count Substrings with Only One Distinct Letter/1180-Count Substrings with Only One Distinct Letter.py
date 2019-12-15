class Solution:
    def countLetters(self, S: str) -> int:
        total = start = 0
        for i, c in enumerate(S):
            if c != S[start]:
                total += (i - start) * (i - start + 1) // 2
                start = i
        total += (len(S) - start) * (len(S) - start + 1) // 2
        return total
