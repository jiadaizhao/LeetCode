class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort(reverse=True)
        half = len(nums) // 2
        nums[::2], nums[1::2] = nums[half:], nums[:half]
