import collections
class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        table = collections.Counter()
        for b in B:
            count = collections.Counter(b)
            for k, v in count.items():
                table[k] = max(table[k], v)
        result = []
        for a in A:
            count = collections.Counter(a)
            if all(count[k] >= v for k, v in table.items()):
                result.append(a)
        return result
