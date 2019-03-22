import math
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        small = big = math.inf
        for num in nums:
            if num <= small:
                small = num
            elif num <= big:
                big = num
            else:
                return True
        return False
