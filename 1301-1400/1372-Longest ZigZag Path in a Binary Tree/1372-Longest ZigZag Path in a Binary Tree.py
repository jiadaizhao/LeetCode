# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def longestZigZag(self, root: TreeNode) -> int:
        maxLen = 0
        def dfs(root):
            if root is None:
                return [-1, -1]
            left = dfs(root.left)
            right = dfs(root.right)
            nonlocal maxLen
            maxLen = max(maxLen, 1 + max(left[1], right[0]))
            return [1 + left[1], 1 + right[0]]
        dfs(root)
        return maxLen
