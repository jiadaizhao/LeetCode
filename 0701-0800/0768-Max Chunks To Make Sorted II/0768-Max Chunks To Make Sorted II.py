class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        maxLeft = [arr[0]] * len(arr)
        for i in range(1, len(arr)):
            maxLeft[i] = max(maxLeft[i - 1], arr[i])
        minRight = arr[-1]
        count = 1
        for i in range(len(arr) - 2, -1, -1):
            minRight = min(minRight, arr[i + 1])
            if maxLeft[i] <= minRight:
                count += 1
        return count
