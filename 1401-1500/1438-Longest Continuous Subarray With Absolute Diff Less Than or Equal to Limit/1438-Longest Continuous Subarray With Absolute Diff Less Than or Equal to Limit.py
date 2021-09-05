import collections
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        start = maxLen = 0
        maxDq = collections.deque()
        minDq = collections.deque()
        for i, num in enumerate(nums):
            while maxDq and num > maxDq[-1]:
                maxDq.pop()
            while minDq and num < minDq[-1]:
                minDq.pop()
            maxDq.append(num)
            minDq.append(num)
            while maxDq[0] - minDq[0] > limit:
                if maxDq[0] == nums[start]:
                    maxDq.popleft()
                if minDq[0] == nums[start]:
                    minDq.popleft()
                start += 1
            maxLen = max(maxLen, i - start + 1)
        return maxLen
