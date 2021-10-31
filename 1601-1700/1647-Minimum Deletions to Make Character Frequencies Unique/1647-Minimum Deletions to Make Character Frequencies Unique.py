import collections
class Solution:
    def minDeletions(self, s: str) -> int:
        table = collections.Counter(s)
        used = set()
        count = 0
        for c, freq in table.items():
            while freq in used and freq > 0:
                freq -= 1
                count += 1
            if freq > 0:
                used.add(freq)
        return count
