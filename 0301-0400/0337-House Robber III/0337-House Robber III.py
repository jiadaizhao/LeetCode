# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        def dfs(root):
            if root is None:
                return [0, 0]
            
            left = dfs(root.left)
            right = dfs(root.right)
            return root.val + left[1] + right[1], max(left) + max(right)

        return max(dfs(root))
