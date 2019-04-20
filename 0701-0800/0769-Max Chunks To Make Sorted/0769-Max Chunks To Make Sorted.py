class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        maxNum = count = 0
        for i, a in enumerate(arr):
            maxNum = max(maxNum, a)
            if maxNum == i:
                count += 1
        return count
