# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        St = []
        presum = 0
        node = root
        while St or node:
            if node:
                St.append(node)
                node = node.right
            else:
                node = St.pop()
                node.val += presum
                presum = node.val
                node = node.left
        return root
