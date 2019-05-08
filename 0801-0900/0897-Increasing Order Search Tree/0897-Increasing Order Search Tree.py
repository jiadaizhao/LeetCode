# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        St = []
        node = root
        prev = None
        while node or St:
            if node:
                St.append(node)
                node = node.left
            else:
                node = St.pop()
                node.left = None
                if prev:
                    prev.right = node
                else:
                    res = node
                prev = node
                node = node.right
        return res
