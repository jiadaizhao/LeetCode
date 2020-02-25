import collections
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = collections.defaultdict(list)
        for s, d in sorted(tickets, reverse=True):
            graph[s].append(d)
        result = []
        def dfs(curr):
            while graph[curr]:
                dfs(graph[curr].pop())
            result.append(curr)
        dfs('JFK')
        return result[::-1]


class Solution2:
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
