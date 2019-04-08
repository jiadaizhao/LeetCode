# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def printTree(self, root: TreeNode) -> List[List[str]]:
        def height(root):
            if root is None:
                return 0
            return 1 + max(height(root.left), height(root.right))
        rows = height(root)
        cols = (1 << rows) - 1
        result = [[''] * cols for _ in range(rows)]
        def fill(node, level, l, r):
            if node is None:
                return
            mid = (l + r) // 2
            result[level][mid] = str(node.val)
            fill(node.left, level + 1, l, mid - 1)
            fill(node.right, level + 1, mid + 1, r)
        fill(root, 0, 0, cols - 1)
        return result
