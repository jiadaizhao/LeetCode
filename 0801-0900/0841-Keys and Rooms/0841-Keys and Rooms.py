class Solution:
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        visited = {0}
        Q = [0]
        while len(Q):
            index = Q.pop(0)
            for k in rooms[index]:
                if k not in visited:
                    Q.append(k)
                    visited.add(k)
        return len(visited) == len(rooms)
