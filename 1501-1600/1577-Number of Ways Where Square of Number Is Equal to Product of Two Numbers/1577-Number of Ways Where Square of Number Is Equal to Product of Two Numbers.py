from functools import lru_cache
import collections
class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        def countNum(target, nums):
            total = 0
            table = collections.Counter()
            for num in nums:
                if target % num == 0:
                    total += table[target // num]
                table[num] += 1
            return total
        @lru_cache(None)
        def countNum1(target):
            return countNum(target, nums2)
        
        @lru_cache(None)
        def countNum2(target):
            return countNum(target, nums1)
        return sum(countNum1(num * num) for num in nums1) + sum(countNum2(num * num) for num in nums2)
