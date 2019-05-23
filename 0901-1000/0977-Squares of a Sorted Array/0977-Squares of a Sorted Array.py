class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        result = [0] * len(A)
        left = 0
        right = len(A) - 1
        for i in range(len(A) - 1, -1, -1):
            if A[left] ** 2 <= A[right] ** 2:
                result[i] = A[right] ** 2
                right -= 1
            else:
                result[i] = A[left] ** 2
                left += 1

        return result
