import collections
import itertools
import math
class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        points = [complex(*z) for z in points]
        table = collections.defaultdict(list)
        for P, Q in itertools.combinations(points, 2):
            center = (P + Q) / 2
            radius = abs(center - P)
            table[center, radius].append(P)
        
        minArea = math.inf
        for (center, radius), candidates in table.items():
            for P, Q in itertools.combinations(candidates, 2):
                minArea = min(minArea, abs(P - Q) * abs(P - (center*2 - Q)))
        return minArea if minArea != math.inf else 0
