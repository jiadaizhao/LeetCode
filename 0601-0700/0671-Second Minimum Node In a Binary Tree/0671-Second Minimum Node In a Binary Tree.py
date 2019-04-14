# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        def helper(root, smallest):
            if root is None:
                return -1
            if root.val != smallest:
                return root.val
            left = helper(root.left, smallest)
            right = helper(root.right, smallest)
            if left == -1:                
                return right
            elif right == -1:
                return left
            else:
                return min(left, right)
        return helper(root, root.val)
