import collections
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        table = collections.Counter(t)
        count = len(table)
        start = 0
        minSize = len(s) + 1
        result = ''
        for i in range(len(s)):
            table[s[i]] -= 1
            if table[s[i]] == 0:
                count -= 1
                while count == 0:
                    if i - start + 1 < minSize:
                        minSize = i - start + 1
                        result = s[start: i+1]
                    table[s[start]] += 1
                    if table[s[start]] == 1:
                        count += 1
                    start += 1

        return result
