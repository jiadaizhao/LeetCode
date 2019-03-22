class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and 3486784401 % n == 0
