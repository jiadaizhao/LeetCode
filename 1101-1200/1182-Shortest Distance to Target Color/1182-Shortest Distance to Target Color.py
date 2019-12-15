import collections
import bisect
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        table = collections.defaultdict(list)
        for i, c in enumerate(colors):
            table[c].append(i)
            
        result = []
        for i, c in queries:
            if c in table:
                index = bisect.bisect_left(table[c], i)
                if index == 0:
                    result.append(table[c][0] - i)
                elif index == len(table[c]):
                    result.append(i - table[c][-1])
                else:
                    result.append(min(table[c][index] - i, i - table[c][index - 1]))
            else:
                result.append(-1)
        return result


class Solution2:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        dist = [[-1] * 3 for _ in range(len(colors))]
        dist[0][colors[0] - 1] = 0
        for i in range(1, len(colors)):
            for c in range(3):
                if dist[i - 1][c] != -1:
                    dist[i][c] = dist[i - 1][c] + 1
            dist[i][colors[i] - 1] = 0

        for i in range(len(colors) - 2, -1, -1):
            for c in range(3):
                if dist[i + 1][c] != -1 and (dist[i][c] == -1 or dist[i + 1][c] + 1 < dist[i][c]):
                    dist[i][c] = dist[i + 1][c] + 1
                    
        return [dist[i][c - 1] for i, c in queries]
