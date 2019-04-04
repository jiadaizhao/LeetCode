# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import math
class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        St = []
        minDiff = math.inf
        prev = None
        node = root
        while St or node:
            if node:
                St.append(node)
                node = node.left
            else:
                node = St.pop()
                if prev:
                    minDiff = min(minDiff, node.val - prev.val)
                prev = node
                node = node.right
        return minDiff
                