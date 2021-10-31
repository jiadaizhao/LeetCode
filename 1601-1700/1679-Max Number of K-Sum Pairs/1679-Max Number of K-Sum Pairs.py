import collections
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        table = collections.Counter(nums)
        result = 0
        for num, count in table.items():
            if num * 2 == k:
                result += count // 2
            elif num * 2 < k:
                result += min(count, table[k - num])
        return result
