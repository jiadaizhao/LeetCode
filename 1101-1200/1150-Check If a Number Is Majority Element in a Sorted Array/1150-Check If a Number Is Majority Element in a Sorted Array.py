import bisect
class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        index1 = bisect.bisect_left(nums, target)
        if index1 == len(nums) or nums[index1] != target:
            return False
        index2 = index1 + len(nums) // 2
        return index2 < len(nums) and nums[index2] == target
