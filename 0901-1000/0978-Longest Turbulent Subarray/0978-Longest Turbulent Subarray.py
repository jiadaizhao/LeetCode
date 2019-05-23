class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
        maxLen = inc = dec = 1
        for i in range(1, len(A)):
            if A[i] > A[i - 1]:
                inc = dec + 1
                maxLen = max(maxLen, inc)
                dec = 1
            elif A[i] < A[i - 1]:
                dec = inc + 1
                maxLen = max(maxLen, dec)
                inc = 1
            else:
                inc = dec = 1
        return maxLen
