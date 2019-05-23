class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        result = []
        for i in range(len(A), 0, -1):
            j = 0
            while A[j] != i:
                j += 1
            if j != i - 1:
                A[:j + 1] = reversed(A[:j + 1])
                result.append(j + 1)
                A[:i] = reversed(A[:i])
                result.append(i)

        return result
