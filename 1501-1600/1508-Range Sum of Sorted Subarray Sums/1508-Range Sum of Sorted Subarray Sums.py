import heapq
class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        pq = [(num, i + 1) for i, num in enumerate(nums)]
        heapq.heapify(pq)
        result = 0
        MOD = 10 ** 9 + 7
        for i in range(1, right + 1):              
            sum, index = heapq.heappop(pq)
            if i >= left:
                result = (result + sum) % MOD
            if index < n:
                heapq.heappush(pq, (sum + nums[index], index + 1))
        return result
