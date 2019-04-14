import collections
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        degree = minLen = 0
        start = {}
        count = collections.Counter()
        for i, num in enumerate(nums):
            if num not in start:
                start[num] = i
            count[num] += 1
            if count[num] > degree:
                degree = count[num]
                minLen = i - start[num] + 1
            elif count[num] == degree:
                minLen = min(minLen, i - start[num] + 1)
        return minLen
