# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        result = root.val
        while root:
            if abs(root.val - target) < abs(result - target):
                result = root.val
                if abs(result - target) <= 0.5:
                    break
            root = root.right if root.val < target else root.left
        return result
