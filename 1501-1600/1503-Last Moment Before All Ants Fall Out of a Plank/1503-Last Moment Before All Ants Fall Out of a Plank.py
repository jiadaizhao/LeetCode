class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        maxTime = 0
        for l in left:
            maxTime = max(maxTime, l)
        for r in right:
            maxTime = max(maxTime, n - r)
        return maxTime
