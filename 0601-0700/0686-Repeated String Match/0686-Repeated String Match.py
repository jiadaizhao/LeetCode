class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        num = (len(B) - 1) // len(A) + 1
        for i in range(2):
            if B in A * (num + i):
                return num + i
        return -1
