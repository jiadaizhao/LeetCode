class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        n = len(bloomDay)
        if n < m * k:
            return -1
        start, end = 1, max(bloomDay)
        while start < end:
            mid = (start + end) // 2
            count = curr = 0
            for d in bloomDay:
                if d > mid:
                    curr = 0
                else:
                    curr += 1
                    if curr >= k:
                        count += 1
                        curr = 0
            if count >= m:
                end = mid
            else:
                start = mid + 1
        return start
