class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        total = 0
        for i, a in enumerate(arr):
            total += ((i + 1) * (n - i) + 1) // 2 * a
        return total
