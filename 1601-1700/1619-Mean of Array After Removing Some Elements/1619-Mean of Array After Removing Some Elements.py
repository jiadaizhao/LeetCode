class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        skip = len(arr) // 20
        return sum(arr[skip:-skip]) / (len(arr) - skip * 2)
