class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        low, high = 1, max(nums)
        while low < high:
            mid = (low + high) // 2
            count = sum((i + mid - 1) // mid for i in nums)
            if count > threshold:
                low = mid + 1
            else:
                high = mid
        return low
