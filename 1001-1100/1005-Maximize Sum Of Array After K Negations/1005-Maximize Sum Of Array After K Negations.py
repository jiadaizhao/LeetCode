import heapq
import math
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        s = sneg = neg = 0
        absmin = math.inf
        negpq = []
        for a in A:
            absmin = min(absmin, abs(a))
            if a >= 0:
                s += a
            else:
                heapq.heappush(negpq, a)
                neg += 1
                sneg += a

        if K < neg:
            while K:
                s -= heapq.heappop(negpq)
                K -= 1
            while negpq:
                s += heapq.heappop(negpq)
        else:
            s -= sneg
            if (K - neg) & 1:
                s -= absmin * 2

        return s
