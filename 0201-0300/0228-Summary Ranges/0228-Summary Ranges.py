class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        i = 0
        result = []
        while i < len(nums):
            start = i
            while i + 1 < len(nums) and nums[i] + 1 == nums[i + 1]:
                i += 1
            if i == start:
                result.append(str(nums[start]))
            else:
                result.append(str(nums[start]) + '->' + str(nums[i]))
            i += 1
        return result
