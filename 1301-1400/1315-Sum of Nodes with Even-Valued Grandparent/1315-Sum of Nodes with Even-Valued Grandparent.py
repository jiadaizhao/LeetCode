# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        total = 0
        def dfs(root, p, gp):
            if root is None:
                return
            nonlocal total
            if gp and (gp.val & 1) == 0:
                total += root.val
            dfs(root.left, root, p)
            dfs(root.right, root, p)
            
        dfs(root, None, None)
        return total
