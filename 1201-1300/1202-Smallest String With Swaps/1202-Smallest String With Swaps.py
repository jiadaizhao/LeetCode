import collections
class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        parent = list(range(len(s)))
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        for a, b in pairs:
            pa = findParent(a)
            pb = findParent(b)
            if pa != pb:
                parent[pb] = pa

        table = collections.defaultdict(list)
        for i, c in enumerate(s):
            table[findParent(i)].append(c)

        for p in table:
            table[p].sort(reverse=True)

        result = []
        for i in range(len(s)):
            result.append(table[findParent(i)].pop())

        return ''.join(result)
