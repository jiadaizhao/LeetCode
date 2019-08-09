class Solution:
    def longestDecomposition(self, text: str, count=0) -> int:
        for i in range(1, len(text) // 2 + 1):
            if text[:i] == text[-i:]:
                return self.longestDecomposition(text[i: -i], count + 2)
        return count + 1 if text else count
