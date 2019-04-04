import collections
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        presum = count = 0
        table = collections.Counter([0])
        for num in nums:
            presum += num
            count += table[presum - k]
            table[presum] += 1
        return count
