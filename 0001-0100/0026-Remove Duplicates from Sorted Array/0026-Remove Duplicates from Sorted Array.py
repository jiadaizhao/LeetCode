class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = 0
        for i in range(len(nums)):
            if count == 0 or nums[i] != nums[i - 1]:
                nums[count] = nums[i]
                count += 1
        return count
