# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        total = 0
        def dfs(root, curr):
            if root is None:
                return
            curr = curr * 2 + root.val
            if root.left is None and root.right is None:
                nonlocal total
                total += curr
            else:
                dfs(root.left, curr)
                dfs(root.right, curr)
        dfs(root, 0)
        return total


class Solution2:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def dfs(root, curr):
            if root is None:
                return 0
            curr = curr * 2 + root.val
            if root.left is None and root.right is None:
                return curr
            else:
                return dfs(root.left, curr) + dfs(root.right, curr)
        return dfs(root, 0)
