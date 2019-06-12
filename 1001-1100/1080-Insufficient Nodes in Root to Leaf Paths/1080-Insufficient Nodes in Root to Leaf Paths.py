# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        def dfs(root, curr):
            if root is None:
                return True

            curr += root.val
            if root.left is None and root.right is None:
                return curr < limit
            else:
                left = dfs(root.left, curr)
                right = dfs(root.right, curr)
                if left:
                    root.left = None
                if right:
                    root.right = None

                return left and right

        return None if dfs(root, 0) else root
