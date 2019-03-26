import math
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        maxNums = [-math.inf] * 3
        for num in nums:
            if num > maxNums[0]:
                maxNums = [num, maxNums[0], maxNums[1]]
            elif num != maxNums[0] and num > maxNums[1]:
                maxNums[1], maxNums[2] = num, maxNums[1]
            elif num != maxNums[0] and num != maxNums[1] and num > maxNums[2]:
                maxNums[2] = num
        
        return maxNums[2] if -math.inf not in maxNums else maxNums[0]
