class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        total = sum(cardPoints)
        sz = n - k
        curr = minSum = sum(cardPoints[:sz])        
        for i in range(sz, n):
            curr += cardPoints[i] - cardPoints[i - sz]
            minSum = min(minSum, curr)
        return total - minSum
