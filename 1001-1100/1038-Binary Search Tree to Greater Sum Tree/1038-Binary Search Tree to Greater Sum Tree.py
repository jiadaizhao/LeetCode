# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        St = []
        node = root
        prev = None
        while node or St:
            if node:
                St.append(node)
                node = node.right
            else:
                node = St.pop()
                if prev:
                    node.val += prev.val
                prev = node
                node = node.left
        return root
