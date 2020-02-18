import collections
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        table = collections.Counter()
        start = count = maxLen = 0
        for i, c in enumerate(s):
            table[c] += 1
            if table[c] == 1:
                count += 1
                while count > k:
                    table[s[start]] -= 1
                    if table[s[start]] == 0:
                        count -= 1
                    start += 1
            maxLen = max(maxLen, i - start + 1)
        return maxLen
