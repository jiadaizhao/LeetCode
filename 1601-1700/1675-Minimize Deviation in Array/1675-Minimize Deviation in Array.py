import heapq
import math
class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        pq = []
        minNum = math.inf
        for num in nums:
            if num & 1:
                num *= 2
            heapq.heappush(pq, -num)
            minNum = min(minNum, num)
        
        minDev = math.inf
        while pq[0] & 1 == 0:
            top = heapq.heappop(pq)
            val = -top
            minDev = min(minDev, val - minNum)
            heapq.heappush(pq, top // 2)
            minNum = min(minNum, val // 2)
        
        return min(minDev, -pq[0] - minNum) 
