import collections
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        table = collections.Counter(nums)
        return sorted(nums, key=lambda x: (table[x], -x))
