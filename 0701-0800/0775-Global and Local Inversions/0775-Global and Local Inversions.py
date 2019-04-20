class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        maxNum = A[0]
        for i in range(len(A) - 2):
            maxNum = max(maxNum, A[i])
            if maxNum > A[i + 2]:
                return False
        return True

class Solution2:
    def isIdealPermutation(self, A: List[int]) -> bool:
        return all(abs(a - i) <= 1 for i, a in enumerate(A))
