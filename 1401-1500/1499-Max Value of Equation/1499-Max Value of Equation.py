import collections
import math
class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        dq = collections.deque()
        result = -math.inf
        for x, y in points:
            while dq and x - dq[0][1] > k:
                dq.popleft()
            if dq:
                result = max(result, dq[0][0] + x + y)
            while dq and dq[-1][0] <= y - x:
                dq.pop()
            dq.append((y - x, x))
        return result
