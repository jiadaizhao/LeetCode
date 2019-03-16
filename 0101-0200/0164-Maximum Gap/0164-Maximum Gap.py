import math
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0

        maxNum = max(nums)
        minNum = min(nums)
        if maxNum - minNum <= 1:
            return maxNum - minNum
        gap = math.ceil((maxNum - minNum + 1) / (len(nums) - 1))
        bucketMax = [-math.inf] * (len(nums) - 1)
        bucketMin = [math.inf] * (len(nums) - 1)
        for num in nums:
            index = (num - minNum) // gap
            bucketMax[index] = max(bucketMax[index], num)
            bucketMin[index] = min(bucketMin[index], num)

        maxGap = 0
        previous = minNum
        for i in range(len(bucketMax)):
            if bucketMin[i] == math.inf:
                continue
            maxGap = max(maxGap, bucketMin[i] - previous)
            previous = bucketMax[i]

        return max(maxGap, bucketMax[-1] - bucketMin[-1])
