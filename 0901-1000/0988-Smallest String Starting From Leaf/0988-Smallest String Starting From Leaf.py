# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        def dfs(root, prev):
            if root is None:
                return '{'
            curr = chr(ord('a') + root.val) + prev
            if root.left is None and root.right is None:
                return curr
            else:
                return min(dfs(root.left, curr), dfs(root.right, curr))
        return dfs(root, '')
