# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        if root is None or root.val < val:
            node = TreeNode(val)
            node.left = root
            return node
        else:
            root.right = self.insertIntoMaxTree(root.right, val)
            return root


class Solution2:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        prev = None
        curr = root
        while curr and curr.val > val:
            prev = curr
            curr = curr.right
        
        node = TreeNode(val)
        node.left = curr
        if prev:
            prev.right = node
        
        return root if prev else node
   