import math
class Solution:
    def minSwap(self, A: List[int], B: List[int]) -> int:
        preserve = [math.inf] * len(A)
        swap = [math.inf] * len(A)
        preserve[0] = 0
        swap[0] = 1
        for i in range(1, len(A)):
            if A[i - 1] < A[i] and B[i - 1] < B[i]:
                preserve[i] = preserve[i - 1]
                swap[i] = swap[i - 1] + 1
            if A[i - 1] < B[i] and B[i - 1] < A[i]:
                preserve[i] = min(preserve[i], swap[i - 1])
                swap[i] = min(swap[i], preserve[i - 1] + 1)
        return min(preserve[-1], swap[-1])

# Optimize space
class Solution2:
    def minSwap(self, A: List[int], B: List[int]) -> int:
        preserve = 0
        swap = 1
        for i in range(1, len(A)):
            preserve2 = swap2 = math.inf
            if A[i - 1] < A[i] and B[i - 1] < B[i]:
                preserve2 = preserve
                swap2 = swap + 1
            if A[i - 1] < B[i] and B[i - 1] < A[i]:
                preserve2 = min(preserve2, swap)
                swap2 = min(swap2, preserve + 1)
            preserve, swap = preserve2, swap2
        return min(preserve, swap)
