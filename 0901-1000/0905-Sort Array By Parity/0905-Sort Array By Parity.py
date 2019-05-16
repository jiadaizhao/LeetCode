class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        start = 0
        end = len(A) - 1
        while start < end:
            if A[start] & 1:
                A[start], A[end] = A[end], A[start]
                end -= 1
            else:
                start += 1
        return A
