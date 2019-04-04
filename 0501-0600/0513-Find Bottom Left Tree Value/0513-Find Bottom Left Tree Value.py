# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        Q = collections.deque([root])
        while Q:
            result = Q[0].val
            l = len(Q)
            for i in range(l):
                node = Q.popleft()
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
        return result
