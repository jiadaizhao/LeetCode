import collections
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        table = collections.defaultdict(list)
        for s in strs:
            table[''.join(sorted(s))].append(s)
        return list(table.values())
