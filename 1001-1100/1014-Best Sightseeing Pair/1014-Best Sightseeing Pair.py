class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        maxScore = -len(A)
        maxLocal = A[0]
        for i in range(1, len(A)):
            maxScore = max(maxScore, A[i] - i + maxLocal)
            maxLocal = max(maxLocal, A[i] + i)
        return maxScore
