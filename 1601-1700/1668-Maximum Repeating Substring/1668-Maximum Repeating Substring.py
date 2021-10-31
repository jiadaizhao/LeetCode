class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        k = 0
        s = word
        while s in sequence:
            k += 1
            s += word
        return k
