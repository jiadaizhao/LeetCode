class Solution:
    def minOperations(self, nums: List[int]) -> int:
        result = maxLen = 0
        for num in nums:
            bits = 0
            while num:
                if num & 1:
                    result += 1
                bits += 1
                num >>= 1
            maxLen = max(maxLen, bits - 1)
        return result + maxLen
