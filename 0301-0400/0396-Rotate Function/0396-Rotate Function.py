class Solution:
    def maxRotateFunction(self, A: 'List[int]') -> 'int':
        s = sum(A)
        curr = sum(i*a for i, a in enumerate(A))
        maxVal = curr
        for i in range(1, len(A)):
            curr += s - len(A)*A[-i]
            maxVal = max(maxVal, curr)
        return maxVal
