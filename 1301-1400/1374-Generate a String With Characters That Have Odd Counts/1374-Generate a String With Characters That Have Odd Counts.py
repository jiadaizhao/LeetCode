class Solution:
    def generateTheString(self, n: int) -> str:
        return 'a' + 'ba'[n & 1] * (n - 1)
