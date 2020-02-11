# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        MOD = 10 ** 9 + 7
        maxP = total = 0
        def dfs(root):            
            if root is None:
                return 0
            sub = dfs(root.left) + root.val + dfs(root.right)
            nonlocal maxP
            maxP = max(maxP, sub * (total - sub))
            return sub
            
        total = dfs(root)
        dfs(root)
        return maxP % MOD
