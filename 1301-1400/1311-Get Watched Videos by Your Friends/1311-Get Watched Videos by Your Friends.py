import collections
class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        Q = collections.deque([id])
        visited = set([id])
        i = 0
        while Q:
            for _ in range(len(Q)):
                curr = Q.popleft()
                for f in friends[curr]:
                    if f not in visited:
                        Q.append(f)
                        visited.add(f)
            
            i += 1
            if i == level:
                break
                
        table = collections.Counter([v for f in Q for v in watchedVideos[f]])
        return sorted(table, key = lambda k: (table[k], k))
