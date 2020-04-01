class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        low, high = 0, n - 1
        while low <= high:
            mid = (low + high) // 2
            if citations[mid] == n - mid:
                return n - mid            
            elif citations[mid] > n - mid:
                high = mid - 1
            else:
                low = mid + 1
        return n - low
