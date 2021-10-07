class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        candidate = arr[0]
        count = 0
        for i in range(1, len(arr)):
            if arr[i] > candidate:
                candidate = arr[i]
                count = 1
            else:
                count += 1
            if count == k:
                return candidate
        return max(arr)
