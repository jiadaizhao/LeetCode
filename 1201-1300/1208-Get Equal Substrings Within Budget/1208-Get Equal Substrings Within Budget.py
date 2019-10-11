class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        arr = [abs(ord(a) - ord(b)) for a, b in zip(s, t)]
        start = cost = maxLen = 0
        for i, a in enumerate(arr):
            cost += a
            while cost > maxCost:
                cost -= arr[start]
                start += 1
            maxLen = max(maxLen, i - start + 1)
        return maxLen
