class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        down = False
        for i in range(len(nums) - 1):
            if (down and nums[i] < nums[i + 1]) or (not down and nums[i] > nums[i + 1]):
                nums[i], nums[i + 1] = nums[i + 1], nums[i]
            down = not down
