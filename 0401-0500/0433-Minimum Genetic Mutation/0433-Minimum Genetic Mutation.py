import collections
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        if end not in bank:
            return -1
        table = collections.defaultdict(list)
        L = len(start)
        for gene in bank:
            for i in range(L):
                table[gene[:i] + '*' + gene[i+1:]].append(gene)
        
        step = 0
        visitedBegin = set([start])
        visitedEnd = set([end])
        visited = set([start, end])
        while visitedBegin and visitedEnd:
            if len(visitedBegin) > len(visitedEnd):
                visitedBegin, visitedEnd = visitedEnd, visitedBegin
            
            step += 1
            temp = set()
            for g in visitedBegin:
                for i in range(L):
                    ng = g[:i] + '*' + g[i+1:]
                    for gene in table[ng]:
                        if gene in visitedEnd:
                            return step
                        if gene not in visited:
                            temp.add(gene)
                            visited.add(gene)
            visitedBegin = temp
        
        return -1
