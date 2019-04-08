# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        if root is None:
            return False
        table = set()
        St = [root]
        while St:
            node = St.pop()
            if k - node.val in table:
                return True
            table.add(node.val)
            if node.right:
                St.append(node.right)
            if node.left:
                St.append(node.left)
        return False