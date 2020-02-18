import itertools
class Solution:
    def nextClosestTime(self, time: str) -> str:
        curr = int(time[:2]) * 60 + int(time[3:])
        minDiff = 1440
        result = curr
        allowed = {int(t) for t in time if t != ':'}
        for h1, h2, m1, m2 in itertools.product(allowed, repeat=4):
            hours, mins = 10 * h1 + h2, 10 * m1 + m2
            if hours < 24 and mins < 60:
                next = hours * 60 + mins
                diff = (next - curr) % 1440
                if 0 < diff < minDiff:
                    minDiff = diff
                    result = next
        return '{:02}:{:02}'.format(*divmod(result, 60))
