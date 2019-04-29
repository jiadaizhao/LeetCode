# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        def contain1(root):
            if root is None:
                return False
            left = contain1(root.left)
            right = contain1(root.right)
            if not left:
                root.left = None
            if not right:
                root.right = None
            return root.val == 1 or left or right
        return root if contain1(root) else None
