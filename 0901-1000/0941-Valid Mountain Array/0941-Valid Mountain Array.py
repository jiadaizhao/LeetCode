class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        i = 0
        while i < len(A) - 1 and A[i] < A[i + 1]:
            i += 1
        if i == 0 or i == len(A) - 1:
            return False
        while i < len(A) - 1 and A[i] > A[i + 1]:
            i += 1
        return i == len(A) - 1
