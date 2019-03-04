# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def contain1(root):
            if not root:
                return False
            left = contain1(root.left)
            right = contain1(root.right)
            if not left:
                root.left = None
            if not right:
                root.right = None
            return left or right or root.val == 1
        
        return root if contain1(root) else None
