class Solution:
    def rotatedDigits(self, N: int) -> int:
        count = 0
        for i in range(1, N + 1):
            s = str(i)
            count += all(c not in '347' for c in s) and any(c in '2569' for c in s)
        return count
