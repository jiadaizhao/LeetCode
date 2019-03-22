import collections
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        table = collections.Counter(nums1)
        result = []
        for num in nums2:
            if table[num] > 0:
                table[num] -= 1
                result.append(num)
        return result
