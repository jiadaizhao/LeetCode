class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        low, high = 0, n
        while low < high:
            mid = (low + high) // 2
            if citations[mid] >= n - mid:
                high = mid
            else:
                low = mid + 1
        return n - low
