import collections
class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        table = collections.Counter(nums[i] * nums[j] for i in range(len(nums)) for j in range(i))
        result = 0
        for v in table.values():
            result += v * (v - 1) * 4
        return result
