import collections
class Solution:
    def characterReplacement(self, s: 'str', k: 'int') -> 'int':
        maxLen = count = start = 0
        table = collections.Counter()
        for i in range(len(s)):
            table[s[i]] += 1
            count = max(count, table[s[i]])
            while i - start + 1 > count + k:
                table[s[start]] -= 1
                start += 1
            maxLen = max(maxLen, i - start + 1)
        return maxLen
