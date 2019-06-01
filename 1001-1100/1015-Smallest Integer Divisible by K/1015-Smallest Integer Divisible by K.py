class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0 or K % 5 == 0:
            return -1
        curr = 0
        visited = set()
        for i in range(1, K + 1):
            curr = (curr * 10 + 1) % K
            if curr == 0:
                return i
            if curr in visited:
                return -1
            visited.add(curr)
        return -1


class Solution2:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0 or K % 5 == 0:
            return -1
        curr = 0
        for i in range(1, K + 1):
            curr = (curr * 10 + 1) % K
            if curr == 0:
                return i
        return -1
