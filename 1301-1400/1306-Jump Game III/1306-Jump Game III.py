import collections
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if arr[start] == 0:
            return True
        visited = set([start])
        Q = collections.deque([start])
        while Q:
            curr = Q.popleft()
            for next in (curr - arr[curr], curr + arr[curr]):
                if 0 <= next < len(arr):
                    if arr[next] == 0:
                        return True
                    if next not in visited:
                        visited.add(next)
                        Q.append(next)
        
        return False    
