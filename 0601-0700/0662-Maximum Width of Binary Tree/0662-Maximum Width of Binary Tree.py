# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if root is None:
            return 0
        maxWid = 1
        Q = collections.deque([(root, 0)])
        while Q:
            maxWid = max(maxWid, Q[-1][1] - Q[0][1] + 1)
            qs = len(Q)
            for i in range(qs):
                node, index = Q.popleft()
                if node.left:
                    Q.append((node.left, index * 2))
                if node.right:
                    Q.append((node.right, index * 2 + 1))
        return maxWid
