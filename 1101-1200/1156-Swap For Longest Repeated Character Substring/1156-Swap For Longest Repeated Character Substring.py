from itertools import groupby
from collections import Counter
class Solution:
    def maxRepOpt1(self, text: str) -> int:
        group = [(k, len(list(g))) for k, g in groupby(text)]
        table = Counter(text)
        maxLen = max(min(table[k], v + 1) for k, v in group)
        for i in range(1, len(group) - 1):
            if group[i - 1][0] == group[i + 1][0] and group[i][1] == 1:
                maxLen = max(maxLen, min(table[group[i - 1][0]], group[i - 1][1] + 1 + group[i + 1][1]))
        return maxLen
