# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def upsideDownBinaryTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return root
        curr = root
        prev = prevRight = None
        while curr:
            next = curr.left
            curr.left = prevRight
            prevRight = curr.right
            curr.right = prev
            
            prev = curr
            curr = next
        return prev