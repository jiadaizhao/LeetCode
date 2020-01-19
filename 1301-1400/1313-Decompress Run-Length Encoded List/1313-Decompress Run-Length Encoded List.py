class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        result = []
        for i in range(0, len(nums), 2):
            a, b = nums[i], nums[i + 1]
            result += [b] * a
        return result
