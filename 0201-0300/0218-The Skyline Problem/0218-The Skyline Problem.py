import heapq
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        result = []
        i = 0
        live = []
        while i < len(buildings) or live:
            if not live or (i < len(buildings) and buildings[i][0] <= -live[0][1]):
                x = buildings[i][0]
                while i < len(buildings) and buildings[i][0] == x:
                    heapq.heappush(live, (-buildings[i][2], -buildings[i][1]))
                    i += 1
            else:
                x = -live[0][1]
                while live and -live[0][1] <= x:
                    heapq.heappop(live)
            height = -live[0][0] if live else 0
            if not result or height != result[-1][1]:
                result.append([x, height])
        return result
