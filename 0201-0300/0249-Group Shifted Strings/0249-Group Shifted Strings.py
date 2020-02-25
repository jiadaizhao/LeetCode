import collections
class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        table = collections.defaultdict(list)
        for s in strings:
            table[''.join(chr(ord('a') + (ord(c) - ord(s[0])) % 26) for c in s)].append(s)
        return list(table.values())
