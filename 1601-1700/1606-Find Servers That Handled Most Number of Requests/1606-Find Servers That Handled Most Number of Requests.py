import heapq
class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        available = list(range(k))
        busy = [] 
        result = [0] * k
        for i, a in enumerate(arrival):
            while busy and busy[0][0] <= a:
                _, t = heapq.heappop(busy)
                heapq.heappush(available, i + (t - i) % k)
            if available:
                j = heapq.heappop(available) % k
                heapq.heappush(busy, (a + load[i], j))
                result[j] += 1
        maxNum = max(result)
        return [i for i in range(k) if result[i] == maxNum]
