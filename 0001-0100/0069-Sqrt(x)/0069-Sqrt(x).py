class Solution:
    def mySqrt(self, x: int) -> int:
        low = 0
        high = x
        result = 0
        while low <= high:
            mid = (low + high) // 2
            if mid*mid <= x:
                result = mid
                low = mid + 1
            else:
                high = mid - 1
        return result

class Solution2:
    def mySqrt(self, x: int) -> int:
        r = x
        while r * r > x:
            r = (r + x //r) // 2
        return r
