class Solution:
    def findComplement(self, num: int) -> int:
        limit = 1
        while limit <= num:
            limit <<= 1
        return limit - 1 - num
