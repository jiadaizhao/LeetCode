import collections
class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        maxGroup = m
        group2item = collections.defaultdict(list)
        for i in range(len(group)):
            if group[i] == -1:
                group[i] = maxGroup
                maxGroup += 1
            group2item[group[i]].append(i)

        itemDegree = [0] * n
        groupDegree = [0] * maxGroup
        itemGraph = collections.defaultdict(list)
        groupGraph = collections.defaultdict(list)
        for j, items in enumerate(beforeItems):
            toGroup = group[j]
            for i in items:
                fromGroup = group[i]
                if fromGroup == toGroup:
                    itemGraph[i].append(j)
                    itemDegree[j] += 1
                else:
                    groupGraph[fromGroup].append(toGroup)
                    groupDegree[toGroup] += 1

        Q = collections.deque()
        groupResult = []
        for g, v in enumerate(groupDegree):
            if v == 0:
                Q.append(g)
                groupResult.append(g)

        while Q:
            f = Q.popleft()
            for to in groupGraph[f]:
                groupDegree[to] -= 1
                if groupDegree[to] == 0:
                    Q.append(to)
                    groupResult.append(to)

        if len(groupResult) != maxGroup:
            return []

        result = []
        for g in groupResult:
            num = 0
            for i in group2item[g]:
                if itemDegree[i] == 0:
                    Q.append(i)
                    result.append(i)
                    num += 1

            while Q:
                f = Q.popleft()
                for to in itemGraph[f]:
                    itemDegree[to] -= 1
                    if itemDegree[to] == 0:
                        Q.append(to)
                        result.append(to)
                        num += 1

            if num != len(group2item[g]):
                return []

        return result
