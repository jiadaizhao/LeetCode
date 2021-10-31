import math
import collections
class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        g = math.gcd(a, b)
        if x % g:
            return -1   
        maxVal = a + b + max([x] + forbidden)
        jumps = [0] + [math.inf] * maxVal
        for pos in forbidden:
            jumps[pos] = -1
        Q = collections.deque([0])
        while Q:
            pos = Q.popleft()
            if pos + a <= maxVal and jumps[pos + a] > jumps[pos] + 1:
                Q.append(pos + a)
                jumps[pos + a] = jumps[pos] + 1
            if pos - b > 0 and jumps[pos - b] > jumps[pos] + 1:
                jumps[pos - b] = jumps[pos] + 1
                if pos - b + a <= maxVal and jumps[pos - b + a] > jumps[pos] + 2:
                    Q.append(pos - b + a)
                    jumps[pos - b + a] = jumps[pos] + 2
      
        return jumps[x] if jumps[x] < math.inf else -1
