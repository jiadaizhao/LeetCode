import collections
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = collections.defaultdict(list)
        for s, d in sorted(tickets, reverse=True):
            graph[s].append(d)
        St = ['JFK']
        route = []
        while St:
            curr = St[-1]
            if graph[curr]:
                St.append(graph[curr].pop())
            else:
                route.append(St.pop())
        return route[::-1]
