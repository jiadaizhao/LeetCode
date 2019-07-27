# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if root is None:
                return None, 0

            left, lh = dfs(root.left)
            right, rh = dfs(root.right)
            if lh > rh:
                return left, lh + 1
            elif lh < rh:
                return right, rh + 1
            else:
                return root, lh + 1

        return dfs(root)[0]
