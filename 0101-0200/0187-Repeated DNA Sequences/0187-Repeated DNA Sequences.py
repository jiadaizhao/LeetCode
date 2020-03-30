import collections
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        table = collections.Counter()
        result = []
        for i in range(len(s) - 9):
            ss = s[i: i + 10]
            table[ss] += 1
            if table[ss] == 2:
                result.append(ss)
        return result
