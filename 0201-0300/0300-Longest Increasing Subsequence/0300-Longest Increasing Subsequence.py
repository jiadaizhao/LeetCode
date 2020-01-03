class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [1] * len(nums)
        maxLen = 1
        for j in range(1, len(nums)):
            for i in range(j):
                if nums[j] > nums[i]:
                    dp[j] = max(dp[j], dp[i] + 1)
            maxLen = max(maxLen, dp[j])
        return maxLen


import bisect
class Solution2:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0

        lis = [nums[0]]
        for num in nums[1:]:
            if num > lis[-1]:
                lis.append(num)
            else:
                index = bisect.bisect_left(lis, num)
                lis[index] = num
        return len(lis)
