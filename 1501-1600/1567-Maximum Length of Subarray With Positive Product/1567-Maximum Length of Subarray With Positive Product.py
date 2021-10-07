class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        firstNegative = zeroPosition = -1
        maxLen = count = 0
        for i, num in enumerate(nums):
            if num < 0:
                count += 1
                if firstNegative == -1:
                    firstNegative = i
            if num == 0:
                count = 0
                firstNegative = -1
                zeroPosition = i
            else:
                if count & 1:
                    maxLen = max(maxLen, i - firstNegative)
                else:
                    maxLen = max(maxLen, i - zeroPosition)
        
        return maxLen
