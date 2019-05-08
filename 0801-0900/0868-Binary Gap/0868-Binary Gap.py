class Solution:
    def binaryGap(self, N: int) -> int:
        maxDist = curr = 0
        prev = -1
        while N:
            if N & 1:
                if prev != -1:
                    maxDist = max(maxDist, curr - prev)
                prev = curr
            curr += 1
            N >>= 1
        return maxDist
