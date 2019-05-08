class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        low = 1
        high = max(piles)
        while low < high:
            mid = (low + high) // 2
            count = sum((p + mid - 1) // mid for p in piles)
            if count > H:
                low = mid + 1
            else:
                high = mid

        return low
