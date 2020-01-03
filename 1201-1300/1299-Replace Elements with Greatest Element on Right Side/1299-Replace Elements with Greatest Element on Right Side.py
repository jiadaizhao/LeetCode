class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        result = [-1] * len(arr)
        maxRight = arr[-1]
        for i in range(len(arr) - 2, -1, -1):
            result[i] = maxRight
            maxRight = max(maxRight, arr[i])
        return result
