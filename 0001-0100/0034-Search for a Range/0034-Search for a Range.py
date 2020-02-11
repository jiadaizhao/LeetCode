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
        high = len(nums)
        while low < high:
            mid = (low + high) // 2
            if nums[mid] > target:
                high = mid
            else:
                low = mid + 1
        right = low - 1
        return [left, right]


class Solution2:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1, -1]
        low = 0
        high = len(nums) - 1
        while low < high:
            mid = (low + high) // 2
            if nums[mid] < target:
                low = mid + 1
            else:
                high = mid
        if nums[low] != target:
            return [-1, -1]
        left = low
        high = len(nums) - 1
        while low < high:
            mid = (low + high + 1) // 2
            if nums[mid] > target:
                high = mid - 1
            else:
                low = mid
        right = low
        return [left, right]
