class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        i = len(A) - 2
        while i >= 0 and A[i] <= A[i + 1]:
            i -= 1
        if i == -1:
            return A
        j = len(A) - 1
        while A[j] >= A[i]:
            j -= 1
        while A[j - 1] == A[j]:
            j -= 1
        A[i], A[j] = A[j], A[i]
        return A
