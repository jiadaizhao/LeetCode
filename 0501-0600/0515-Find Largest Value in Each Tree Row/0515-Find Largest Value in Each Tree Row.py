# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        Q = collections.deque([root])
        result = []
        while Q:
            qs = len(Q)
            maxVal = Q[0].val
            for _ in range(qs):
                node = Q.popleft()
                maxVal = max(maxVal, node.val)
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
            result.append(maxVal)
        return result
