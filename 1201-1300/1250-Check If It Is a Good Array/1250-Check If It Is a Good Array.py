import math
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        curr = nums[0]
        for num in nums:
            curr = math.gcd(curr, num)
            if curr == 1:
                return True
        return False
