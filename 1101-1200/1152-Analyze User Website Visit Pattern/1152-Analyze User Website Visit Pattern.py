import collections
from itertools import combinations
from collections import Counter
class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        visit = collections.defaultdict(list)
        for t, u, w in sorted(zip(timestamp, username, website)):
            visit[u].append(w)
        table = sum([Counter(set(combinations(w, 3))) for w in visit.values()], Counter())
        return list(min(table, key=lambda k: (-table[k], k)))
