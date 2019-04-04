class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        maxLen = 0
        for i in range(len(nums)):
            if nums[i] != -1:
                count = 0
                while nums[i] != -1:
                    temp = i
                    i = nums[i]
                    nums[temp] = -1
                    count += 1
                maxLen = max(maxLen, count)
        return maxLen
