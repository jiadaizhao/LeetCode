class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        low = 0
        high = len(nums)
        while low < high:
            mid = (low + high) // 2
            if nums[mid] < target:
                low = mid + 1
            else:
                high = mid
        if low == len(nums) or nums[low] != target:
            return [-1, -1]
        left = low
        low = 0
        high = len(nums)
        while low < high:
            mid = (low + high) // 2
            if nums[mid] > target:
                high = mid
            else:
                low = mid + 1
        right = low - 1
        return [left, right]
