class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        start = count = 0
        product = 1
        for i, num in enumerate(nums):
            product *= num
            while product >= k:
                product //= nums[start]
                start += 1
            count += i - start + 1
        return count
