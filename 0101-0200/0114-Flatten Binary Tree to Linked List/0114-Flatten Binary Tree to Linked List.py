# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None:
            return
        St = [root]
        while St:
            node = St.pop()
            if node.right:
                St.append(node.right)
            if node.left:
                St.append(node.left)
            node.left = None
            if St:
                node.right = St[-1]
