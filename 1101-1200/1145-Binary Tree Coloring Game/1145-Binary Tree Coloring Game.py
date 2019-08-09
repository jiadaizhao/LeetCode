# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        count = [0] * 2
        def dfs(root):
            if root is None:
                return 0

            left = dfs(root.left)
            right = dfs(root.right)    
            if root.val == x:
                count[0] = left
                count[1] = right

            return 1 + left + right
        dfs(root)
        return max(count[0], count[1], n - 1 - count[0] - count[1]) > n // 2
