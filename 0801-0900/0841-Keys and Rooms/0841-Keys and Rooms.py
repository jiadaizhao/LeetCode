import collections
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = [False]*len(rooms)
        Q = collections.deque([0])
        while Q:
            index = Q.popleft()
            visited[index] = True
            for k in rooms[index]:
                if not visited[k]:
                    Q.append(k)
        return all(visited)

class Solution2:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = [False]*len(rooms)
        St = [0]
        while St:
            index = St.pop()
            visited[index] = True
            for k in rooms[index]:
                if not visited[k]:
                    St.append(k)
        return all(visited)
