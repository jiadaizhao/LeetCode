# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low = 1
        high = n + 1
        while low < high:
            mid = (low + high) // 2
            feedback = guess(mid)
            if feedback == -1:
                high = mid
            elif feedback == 1:
                low = mid + 1
            else:
                return mid

        return low
