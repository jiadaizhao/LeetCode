import heapq
class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        A.sort()
        pq = [(-b, i) for i, b in enumerate(B)]
        heapq.heapify(pq)
        low = 0
        high = len(A) - 1
        result = [0] * len(A)
        while pq:
            b, i = heapq.heappop(pq)
            b = -b
            if A[high] > b:
                result[i] = A[high]
                high -= 1
            else:
                result[i] = A[low]
                low += 1
        return result
