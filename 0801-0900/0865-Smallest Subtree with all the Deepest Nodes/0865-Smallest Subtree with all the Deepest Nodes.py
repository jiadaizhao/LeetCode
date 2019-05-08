# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if root is None:
                return None, 0
            left, ld = dfs(root.left)
            right, rd = dfs(root.right)
            if ld < rd:
                return right, rd + 1
            elif ld > rd:
                return left, ld + 1
            else:
                return root, ld + 1
        return dfs(root)[0]
