import collections
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        count = 0
        for p in points:
            table = collections.Counter()
            for q in points:
                diff = (p[0] - q[0])**2 + (p[1] - q[1])**2
                count += table[diff]*2
                table[diff] += 1
        return count
