import math
class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        result = []
        r, c = destination
        down = r
        for i in range(1, r + c + 1):
            count = math.comb(r + c - i, down)
            if count >= k:
                result.append('H')
            else:
                result.append('V')
                down -= 1
                k -= count
        return ''.join(result)
