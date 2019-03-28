import math
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        St = []
        s2 = -math.inf
        for num in nums[::-1]:
            if num < s2:
                return True
            while St and St[-1] < num:
                s2 = St.pop()
            St.append(num)
        return False
