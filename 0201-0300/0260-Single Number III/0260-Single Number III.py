class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        diff = 0
        for num in nums:
            diff ^= num
        lastBitMask = (-diff)&diff
        result = [0, 0]
        for num in nums:
            if num & lastBitMask:
                result[0] ^= num
            else:
                result[1] ^= num
        return result
