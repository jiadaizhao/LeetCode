class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        maxSum = arr[0]
        left = [0] * len(arr)
        left[0] = arr[0]        
        for i in range(1, len(arr)):
            left[i] = max(arr[i], left[i - 1] + arr[i])
            maxSum = max(maxSum, left[i])
            
        right = [0] * len(arr)
        right[-1] = arr[-1]
        for i in range(len(arr) - 2, -1, -1):
            right[i] = max(arr[i], right[i + 1] + arr[i])
            
        for i in range(1, len(arr) - 1):
            maxSum = max(maxSum, left[i - 1] + right[i + 1])
        
        return maxSum


class Solution2:
    def maximumSum(self, arr: List[int]) -> int:
        includeAll = maxSum = arr[0]
        mayDeleteOne = max(arr[0], 0)
        for i in range(1, len(arr)):
            mayDeleteOne = max(arr[i], mayDeleteOne + arr[i], includeAll)
            includeAll = max(arr[i], includeAll + arr[i])
            maxSum = max(maxSum, mayDeleteOne)
            mayDeleteOne = max(mayDeleteOne, 0)
        return maxSum
       