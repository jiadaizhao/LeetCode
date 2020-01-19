import collections
class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        distance = collections.defaultdict(list)
        for i, w in enumerate(workers):
            for j, b in enumerate(bikes):
                distance[abs(w[0] - b[0]) + abs(w[1] - b[1])].append((i, j))

        result = [-1] * len(workers)
        assigned = [False] * len(bikes)
        for d in sorted(distance):
            for wi, bi in distance[d]:
                if result[wi] == -1 and not assigned[bi]:
                    result[wi] = bi
                    assigned[bi] = True

        return result
