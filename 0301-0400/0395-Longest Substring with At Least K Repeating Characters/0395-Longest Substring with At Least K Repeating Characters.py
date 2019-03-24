class Solution:
    def longestSubstring(self, s: 'str', k: 'int') -> 'int':
        for c in set(s):
            if s.count(c) < k:
                return max(self.longestSubstring(t, k) for t in s.split(c))
        return len(s)

import collections
class Solution:
    def longestSubstring(self, s: 'str', k: 'int') -> 'int':
        maxLen = 0
        for i in range(1, len(set(s)) + 1):
            start = 0
            table = collections.Counter()
            unique = 0
            noLessK = 0            
            for j in range(len(s)):
                table[s[j]] += 1
                if table[s[j]] == 1:
                    unique += 1
                if table[s[j]] == k:
                    noLessK += 1
                while unique > i:
                    table[s[start]] -= 1
                    if table[s[start]] == 0:
                        unique -= 1
                    if table[s[start]] == k - 1:
                        noLessK -= 1
                    start += 1
                if unique == i and noLessK == i:
                    maxLen = max(maxLen, j - start + 1)
        return maxLen
