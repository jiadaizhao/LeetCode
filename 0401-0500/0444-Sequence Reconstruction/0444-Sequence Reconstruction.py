import collections
class Solution:
    def sequenceReconstruction(self, org: List[int], seqs: List[List[int]]) -> bool:
        n = len(org)
        validInput = False
        graph = collections.defaultdict(set)
        degrees = [0] * (n + 1)
        for seq in seqs:
            if not seq:
                continue
            validInput = True
            for i in range(len(seq)):
                if seq[i] > n or seq[i] < 1:
                    return False
                if i < len(seq) - 1 and 0 < seq[i + 1] <= n and seq[i + 1] not in graph[seq[i]]:
                    graph[seq[i]].add(seq[i + 1])
                    degrees[seq[i + 1]] += 1
        
        if not validInput:
            return False
        count = 0
        Q = collections.deque([i for i in range(1, n + 1) if degrees[i] == 0])
        while len(Q) == 1:
            curr = Q.popleft()
            if org[count] != curr:
                return False
            count += 1
            for neighbor in graph[curr]:
                degrees[neighbor] -= 1
                if degrees[neighbor] == 0:
                    Q.append(neighbor)
        
        return count == n                    
