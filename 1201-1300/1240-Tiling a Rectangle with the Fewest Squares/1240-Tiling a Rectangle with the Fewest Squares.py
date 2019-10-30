import heapq
class Solution:
    def tilingRectangle(self, n: int, m: int) -> int:
        total_area = n * m
        dp = [0] * (total_area + 1)
        for i in range(1, total_area):
            dp[i] = 1 + min(dp[i - k * k] for k in range(1, int(i ** 0.5) + 1))

        height = [0] * m
        pq = []
        for i in range(1, min(n, m) + 1):
            h = height[:]
            for j in range(i):
                h[j] = i
            heapq.heappush(pq, (1 + dp[total_area - i * i], 1, h))

        while pq:
            guess, count, height = heapq.heappop(pq)
            if all(h == n for h in height):
                return count

            minHeight = min(height)
            minIdx = height.index(minHeight)
            rIdx = minIdx + 1
            while rIdx < m and height[rIdx] == minHeight and rIdx - minIdx + 1 + minHeight <= n:
                rIdx += 1

            for i in range(1, rIdx - minIdx + 1):
                h = height[:]
                for j in range(i):
                    h[minIdx + j] += i
                guess = count + 1 + dp[total_area - sum(h)]
                heapq.heappush(pq, (guess, count + 1, h))

        return -1
