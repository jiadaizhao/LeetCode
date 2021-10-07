class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        if len(arr) == m:
            return m
        length = [0] * (len(arr) + 2)
        last = -1
        for i, a in enumerate(arr):
            left = length[a - 1]
            right = length[a + 1]
            length[a - left] = length[a + right] = left + 1 + right
            if left == m or right == m:
                last = i
        return last
