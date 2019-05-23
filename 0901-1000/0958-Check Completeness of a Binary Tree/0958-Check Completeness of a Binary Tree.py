# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections
class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        Q = collections.deque([root])
        level = 0
        while Q:
            qs = len(Q)
            gap = False
            for _ in range(qs):
                node = Q.popleft()
                if node.left:
                    if gap:
                        return False
                    Q.append(node.left)
                    if node.right:
                        Q.append(node.right)
                    else:
                        gap = True
                elif node.right:
                    return False
                else:
                    gap = True
            if Q and qs != (1 << level):
                return False
            level += 1
        return True
