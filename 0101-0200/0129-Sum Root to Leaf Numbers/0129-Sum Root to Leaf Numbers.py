# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        def dfs(root, prev):
            if root is None:
                return 0
            curr = prev*10 + root.val
            if root.left is None and root.right is None:
                return curr
            else:
                return dfs(root.left, curr) + dfs(root.right, curr)
        return dfs(root, 0)
