class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        for i in range(len(nums) - 1):
            diff = nums[i + 1] - nums[i] - 1
            if k > diff:
                k -= diff
            else:
                return nums[i] + k
        return nums[-1] + k


# Binary search
class Solution2:
    def missingElement(self, nums: List[int], k: int) -> int:
        missing = nums[-1] - nums[0] + 1 - len(nums)
        if missing < k:
            return nums[-1] + k - missing
        
        low = 0
        high = len(nums)
        while low + 1 < high:
            mid = (low + high) // 2
            missing = nums[mid] - nums[low] - (mid - low)
            if missing >= k:
                high = mid
            else:
                k -= missing
                low = mid
        return nums[low] + k
