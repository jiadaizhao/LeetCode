from functools import reduce
import operator
class Solution:
    def singleNumber(self, nums) -> int:
        return reduce(operator.xor, nums)
