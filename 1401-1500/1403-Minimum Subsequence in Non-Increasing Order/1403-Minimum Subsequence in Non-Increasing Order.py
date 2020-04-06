class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=True)
        total = sum(nums)
        result = []
        curr = 0
        for num in nums:
            result.append(num)
            curr += num
            if curr > total - curr:
                break
        return result
