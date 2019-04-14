class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        result = [0] * len(positions)
        intervals = []
        def getHeight(left, right):
            maxH = 0
            for l, r, h in intervals:
                if left <= r and right >= l:
                    maxH = max(maxH, h)
            return maxH
        
        maxHeight = 0
        for i, (left, side) in enumerate(positions):
            right = left + side - 1
            currH = getHeight(left, right) + side
            maxHeight = max(maxHeight, currH)
            intervals.append((left, right, currH))
            result[i] = maxHeight
        return result
