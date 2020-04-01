class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        minLen = len(nums) + 1
        start = sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            while sum >= s:
                minLen = min(minLen, i - start + 1)
                sum -= nums[start]
                start += 1
        return minLen if minLen != len(nums) + 1 else 0
