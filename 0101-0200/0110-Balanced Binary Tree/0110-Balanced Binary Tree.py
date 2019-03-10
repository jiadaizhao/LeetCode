# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def dfs(root):
            if root is None:
                return (True, 0)
            lb, lh = dfs(root.left)
            rb, rh = dfs(root.right)
            h = max(lh, rh) + 1
            return (lb and rb and abs(lh - rh) <= 1, h)
        return dfs(root)[0]
