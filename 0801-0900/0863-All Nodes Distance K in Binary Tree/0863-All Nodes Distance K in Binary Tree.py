# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) -> List[int]:
        parents = {}
        def dfs(root, parent):
            if root is None:
                return
            parents[root] = parent
            dfs(root.left, root)
            dfs(root.right, root)
            
        dfs(root, None)
        Q = collections.deque([target])
        dist = 0
        visited = set([target])
        while Q:
            if dist == K:
                return [node.val for node in Q]
            for _ in range(len(Q)):
                node = Q.popleft()
                if node.left and node.left not in visited:
                    Q.append(node.left)
                    visited.add(node.left)
                if node.right and node.right not in visited:
                    Q.append(node.right)
                    visited.add(node.right)
                if node != root and parents[node] not in visited:
                    Q.append(parents[node])
                    visited.add(parents[node])
            dist += 1
        return []
