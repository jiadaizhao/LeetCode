import heapq
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        ugly = [1] * n
        pq = [(p, 0, p) for p in primes]
        for i in range(1, n):
            ugly[i] = pq[0][0]
            while pq[0][0] == ugly[i]:
                _, index, p = heapq.heappop(pq)
                heapq.heappush(pq, (ugly[index + 1]*p, index + 1, p))
        return ugly[-1]
