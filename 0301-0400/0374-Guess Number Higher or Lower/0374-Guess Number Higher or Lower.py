# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        low = 1
        high = n
        while low <= high:
            mid = (low + high) // 2
            feedback = guess(mid)
            if feedback == -1:
                high = mid - 1
            elif feedback == 1:
                low = mid + 1
            else:
                return mid

        return low
