class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        if m > n:
            m, n = n, m
        low = 1
        high = m * n
        while low < high:
            mid = (low + high) // 2
            count = 0
            for i in range(1, m + 1):
                count += min(mid // i, n)
            if count < k:
                low = mid + 1
            else:
                high = mid
        return low
