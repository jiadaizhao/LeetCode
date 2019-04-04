class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        while low < high:
            mid = (low + high) // 2
            if mid & 1:
                if nums[mid] == nums[mid + 1]:
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if nums[mid] == nums[mid + 1]:
                    low = mid + 2
                else:
                    high = mid
        return nums[low]
