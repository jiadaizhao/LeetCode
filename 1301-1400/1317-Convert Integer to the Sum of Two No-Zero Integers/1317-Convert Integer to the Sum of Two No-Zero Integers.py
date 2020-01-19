class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        A = 1
        while '0' in '{}{}'.format(A, n - A):
            A += 1
        return [A, n - A]
