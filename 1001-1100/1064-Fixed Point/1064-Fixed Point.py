class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        low = 0
        high = len(A) - 1
        while low < high:
            mid = (low + high) // 2
            if A[mid] >= mid:
                high = mid
            else:
                low = mid + 1
                
        return low if A[low] == low else -1
