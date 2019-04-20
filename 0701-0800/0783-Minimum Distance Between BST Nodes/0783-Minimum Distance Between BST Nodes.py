# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import math
class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        St = []
        curr = root
        prev = None
        minDiff = math.inf
        while St or curr:
            if curr:
                St.append(curr)
                curr = curr.left
            else:
                curr = St.pop()
                if prev:
                     minDiff = min(minDiff, curr.val - prev.val)
                prev = curr
                curr = curr.right
        return minDiff
                    