import collections
import bisect
class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        table = collections.defaultdict(list)
        for i, c in enumerate(source):
            table[c].append(i)
            
        i = 0
        count = 1
        for c in target:
            if c not in table:
                return -1
            il = table[c]
            index = bisect.bisect_left(il, i)
            if index == len(il):
                count += 1
                i = il[0] + 1
            else:
                i = il[index] + 1
        return count


class Solution2:
    def shortestWay(self, source: str, target: str) -> int:
        table = [[-1] * 26 for _ in range(len(source))]
        table[-1][ord(source[-1]) - ord('a')] = len(source) - 1
        for i in range(len(source) - 2, -1, -1):
            table[i] = table[i + 1][:]
            table[i][ord(source[i]) - ord('a')] = i
            
        i = 0
        count = 1
        for c in target:
            if table[0][ord(c) - ord('a')] == -1:
                return -1
            index = table[i][ord(c) - ord('a')] if i < len(source) else -1
            if index == -1:
                count += 1
                i = table[0][ord(c) - ord('a')] + 1
            else:
                i = index + 1
        return count
                