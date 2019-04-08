class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        OneDec = False
        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                if OneDec:
                    return False
                OneDec = True
                if i > 1 and nums[i - 2] > nums[i] and i < len(nums) - 1 and nums[i - 1] > nums[i + 1]:
                    return False
        return True
