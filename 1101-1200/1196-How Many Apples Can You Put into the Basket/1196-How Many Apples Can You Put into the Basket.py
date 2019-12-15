class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        count = weight = 0
        for a in sorted(arr):
            weight += a
            if weight > 5000:
                break
            count += 1
        return count
