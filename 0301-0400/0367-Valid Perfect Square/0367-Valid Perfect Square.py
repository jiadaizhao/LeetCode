class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        low = 1
        high = num
        while low <= high:
            mid = (low + high) // 2
            if mid * mid < num:
                low = mid + 1
            elif mid * mid > num:
                high = mid - 1
            else:
                return True
        return False

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        x = num
        while x*x > num:
            x = (x + num // x) >> 1
        return x*x == num
