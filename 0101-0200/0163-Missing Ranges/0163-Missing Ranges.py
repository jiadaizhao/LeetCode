class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        result = []
        prev = lower - 1
        for num in nums:
            if prev + 2 == num:
                result.append(str(prev + 1))
            elif prev + 2 < num:
                result.append(str(prev + 1) + '->' + str(num - 1))
            prev = num
        if prev + 1 == upper:
            result.append(str(prev + 1))
        elif prev + 1 < upper:
            result.append(str(prev + 1) + '->' + str(upper))
        
        return result
