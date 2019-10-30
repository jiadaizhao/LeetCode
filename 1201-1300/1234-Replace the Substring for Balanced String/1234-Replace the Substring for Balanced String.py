import collections
class Solution:
    def balancedString(self, s: str) -> int:
        target = len(s) // 4
        counts = collections.Counter(s)
        start = 0
        minLen = len(s)
        for i, c in enumerate(s):
            counts[c] -= 1
            while (start < len(s) and counts['Q'] <= target and counts['W'] <= target and
                    counts['E'] <= target and counts['R'] <= target):
                minLen = min(minLen, i - start + 1)
                counts[s[start]] += 1
                start += 1

        return minLen
    