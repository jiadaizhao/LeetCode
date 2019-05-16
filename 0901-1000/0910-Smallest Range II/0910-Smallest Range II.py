class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        A.sort()
        result = A[-1] - A[0]
        for i in range(len(A) - 1):
            result = min(result, max(A[i] + K, A[-1] - K) - min(A[i + 1] - K, A[0] + K))
        return result
