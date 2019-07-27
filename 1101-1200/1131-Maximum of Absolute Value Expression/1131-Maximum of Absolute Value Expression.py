class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        maxVal = 0
        for p, q in (-1, -1), (-1, 1), (1, -1), (1, 1):
            minLocal = p * arr1[0] + q * arr2[0]
            for i in range(1, len(arr1)):
                curr = p * arr1[i] + q * arr2[i] + i
                maxVal = max(maxVal, curr - minLocal)
                minLocal = min(minLocal, curr)
        return maxVal
