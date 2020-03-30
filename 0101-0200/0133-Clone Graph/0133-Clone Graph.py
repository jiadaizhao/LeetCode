# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors

import collections
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None
        table = {node: Node(node.val, [])}
        Q = collections.deque([node])
        while Q:
            n = Q.popleft()
            for neighbor in n.neighbors:
                if neighbor not in table:
                    table[neighbor] = Node(neighbor.val, [])
                    Q.append(neighbor)
                table[n].neighbors.append(table[neighbor])
        return table[node]
