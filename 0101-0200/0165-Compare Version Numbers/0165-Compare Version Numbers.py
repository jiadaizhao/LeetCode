from itertools import zip_longest
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = map(int, version1.split('.'))
        v2 = map(int, version2.split('.'))
        v1, v2 = zip(*zip_longest(v1, v2, fillvalue=0))
        return (v1 > v2) - (v1 < v2)
