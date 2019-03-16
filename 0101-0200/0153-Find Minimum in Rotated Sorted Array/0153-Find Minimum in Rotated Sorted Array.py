import math
class Solution:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        while low < high:
            mid = (low + high) // 2
            if nums[mid] < nums[high]:
                high = mid
            else:
                low = mid + 1
        return nums[low]

class Solution2:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        while low  + 1 < high:
            mid = (low + high) // 2
            if nums[mid] < nums[high]:
                high = mid
            else:
                low = mid + 1
        return min(nums[low], nums[high])

class Solution3:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums)
        minNum = math.inf
        while low < high:
            mid = (low + high) // 2
            if nums[mid] <= nums[high - 1]:
                minNum = min(minNum, nums[mid])
                high = mid
            else:
                low = mid + 1
        return minNum