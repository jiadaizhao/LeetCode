import collections
class Solution:
    def sortString(self, s: str) -> str:
        chs = sorted([k, v] for k, v in collections.Counter(s).items())
        result = []
        while len(result) < len(s):
            for i in range(len(chs)):
                if chs[i][1] > 0:
                    result.append(chs[i][0])
                    chs[i][1] -= 1
            for i in range(len(chs)):
                if chs[~i][1] > 0:
                    result.append(chs[~i][0])
                    chs[~i][1] -= 1
        return ''.join(result)
