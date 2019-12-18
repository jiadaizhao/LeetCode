# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        maxLen = 0
        def dfs(root):
            if root is None:
                return 0
            nonlocal maxLen
            left = dfs(root.left)
            right = dfs(root.right)
            maxLen = max(maxLen, left + right)
            return 1 + max(left, right)
        dfs(root)
        return maxLen
