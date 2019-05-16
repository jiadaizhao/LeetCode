import itertools
class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        maxTime = ''
        for h1, h2, m1, m2 in itertools.permutations(A):
            h = h1*10 + h2
            m = m1*10 + m2
            if h < 24 and m < 60:
                time = '{:02}:{:02}'.format(h, m)
                maxTime = max(maxTime, time)
        return maxTime
