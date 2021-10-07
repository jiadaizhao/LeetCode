class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        n = len(position)
        left, right = 1, position[-1] - position[0]
        while left < right:
            mid = (left + right + 1) // 2
            count = 1
            prev = position[0]
            for i in range(1, n):
                if position[i] - prev >= mid:
                    count += 1
                    prev = position[i]
            if count >= m:
                left = mid
            else:
                right = mid - 1
        return left
