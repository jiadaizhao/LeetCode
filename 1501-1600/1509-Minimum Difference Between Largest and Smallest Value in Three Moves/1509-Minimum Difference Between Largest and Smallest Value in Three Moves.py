import heapq
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        return min(a - b for a, b in zip(heapq.nlargest(4, nums), heapq.nsmallest(4, nums)[::-1])) 
