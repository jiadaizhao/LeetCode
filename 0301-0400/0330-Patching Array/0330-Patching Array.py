class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        miss = 1
        i = count = 0
        while miss <= n:
            if i < len(nums) and nums[i] <= miss:
                miss += nums[i]
                i += 1
            else:
                miss <<= 1
                count += 1
        return count
