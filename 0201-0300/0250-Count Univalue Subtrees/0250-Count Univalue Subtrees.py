# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def countUnivalSubtrees(self, root: TreeNode) -> int:
        count = 0
        def isUnivalSubtree(root):
            if root is None:
                return True
            left = isUnivalSubtree(root.left)
            right = isUnivalSubtree(root.right)
            if left and right:
                if root.left and root.val != root.left.val:
                    return False
                if root.right and root.val != root.right.val:
                    return False
                nonlocal count
                count += 1
                return True
            return False
        isUnivalSubtree(root)
        return count
