import heapq
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        MOD = 10 ** 9 + 7
        es = sorted(zip(efficiency, speed), reverse=True)
        maxP = currSum = 0
        pq = []
        for i in range(k):
            heapq.heappush(pq, es[i][1])
            currSum += es[i][1]
            maxP = max(maxP, currSum * es[i][0])
        for i in range(k, n):
            if es[i][1] > pq[0]:
                heapq.heappush(pq, es[i][1])
                currSum += es[i][1] - heapq.heappop(pq)
                maxP = max(maxP, currSum * es[i][0])
        return maxP % MOD
