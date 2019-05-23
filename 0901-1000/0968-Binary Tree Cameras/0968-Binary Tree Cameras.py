# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        total = 0
        def dfs(node):
            if node is None:
                return -1

            left = dfs(node.left)
            right = dfs(node.right)
            if left == 0 or right == 0:
                nonlocal total
                total += 1
                return 1
            
            if left == 1 or right == 1:
                return 2
            else:
                return 0

        return (1 if dfs(root) == 0 else 0) + total
