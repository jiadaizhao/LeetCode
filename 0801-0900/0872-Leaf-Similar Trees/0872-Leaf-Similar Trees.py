# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def dfs(root):
            if root:
                if root.left is None and root.right is None:
                    yield root.val
                else:
                    yield from dfs(root.left)
                    yield from dfs(root.right)

        return list(dfs(root1)) == list(dfs(root2))
