# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        def height(root):
            h = -1
            while root:
                root = root.left
                h += 1
            return h
        
        h = height(root)
        count = 0
        while h >= 0:
            rh = height(root.right)
            if rh == h - 1:
                count += (1 << h)
                root = root.right
            else:
                count += (1 << (h - 1))
                root = root.left
            h -= 1
        return count
