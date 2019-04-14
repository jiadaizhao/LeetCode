# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        inode = TreeNode(val)
        if root is None:
            return inode
        node = root
        while node:
            prev = node
            if node.val < val:
                node = node.right
            else:
                node = node.left
        if prev.val < val:
            prev.right = inode
        else:
            prev.left = inode
        return root