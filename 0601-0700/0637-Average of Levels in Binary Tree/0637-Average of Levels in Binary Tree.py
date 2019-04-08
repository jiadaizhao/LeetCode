# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        Q = collections.deque([root])
        result = []
        while Q:
            qs = len(Q)
            sum = 0
            for _ in range(qs):
                node = Q.popleft()
                sum += node.val
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
            result.append(sum / qs)
        return result
