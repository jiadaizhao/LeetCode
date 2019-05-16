class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        start = 0
        end = len(A) - 1
        while start < len(A) and end >= 0:
            while start < len(A) and A[start] % 2 == 0:
                start += 2
            while end >= 0 and A[end] % 2 == 1:
                end -= 2
            if start < len(A) and end >= 0:
                A[start], A[end] = A[end], A[start]
                start += 2
                end -= 2
        return A
