import collections
import math
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        Q = collections.deque([root])
        index = 0
        while Q:
            prev = -math.inf if index == 0 else math.inf
            for _ in range(len(Q)):
                node = Q.popleft()
                if index == 0:
                    if node.val & 1 == 0:
                        return False
                    if node.val<= prev:
                        return False
                else:
                    if node.val & 1:
                        return False
                    if node.val >= prev:
                        return False
                prev = node.val
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
            index = 1 - index
        return True
