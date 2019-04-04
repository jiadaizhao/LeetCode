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
            nonlocal maxLen
            if root is None:
                return -1
            left = dfs(root.left)
            right = dfs(root.right)
            maxLen = max(maxLen, 2 + left + right)
            return 1 + max(left, right)
        dfs(root)
        return maxLen
