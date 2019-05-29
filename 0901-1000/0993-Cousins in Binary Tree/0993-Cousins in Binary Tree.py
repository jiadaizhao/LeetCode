# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        dx = dy = -1
        px = py = None
        def dfs(root, depth, prev):
            if root is None:
                return
            nonlocal dx, dy, px, py
            if root.val == x:
                px = prev
                dx = depth
                return
            elif root.val == y:
                py = prev
                dy = depth
                return
            
            dfs(root.left, depth + 1, root)
            dfs(root.right, depth + 1, root)
            
        dfs(root, 0, None)
        return dx == dy and px != py
