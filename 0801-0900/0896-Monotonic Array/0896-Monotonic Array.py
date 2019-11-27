class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        inc = dec = False
        for i in range(len(A) - 1):
            if A[i] > A[i + 1]:
                if inc:
                    return False
                dec = True
            elif A[i] < A[i + 1]:
                if dec:
                    return False
                inc = True
        return True
