import collections
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], S: int, T: int) -> int:
        if S == T:
            return 0
        stationToBus = collections.defaultdict(list)
        for i, route in enumerate(routes):
            for station in route:
                stationToBus[station].append(i)
                
        Q = collections.deque([S])
        visitedStation = set([S])
        visitedBus = set()
        step = 0
        while Q:
            step += 1
            for _ in range(len(Q)):
                s = Q.popleft()
                for nb in stationToBus[s]:
                    if nb not in visitedBus:
                        visitedBus.add(nb)
                        for ns in routes[nb]:
                            if ns == T:
                                return step
                            if ns not in visitedStation:
                                Q.append(ns)
                                visitedStation.add(ns)
        
        return -1
