class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        count = s = 0
        for i, a in enumerate(arr):
            s += a
            if i >= k:
                s -= arr[i - k]
            if i >= k - 1 and s / k >= threshold:
                count += 1
        return count
