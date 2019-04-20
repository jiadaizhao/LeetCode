class Solution:
    def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
        count = 0
        left = right = -1
        for i in range(len(A)):
            if A[i] >= L:
                right = i
            if A[i] > R:
                left = i
            count += right - left
        return count
