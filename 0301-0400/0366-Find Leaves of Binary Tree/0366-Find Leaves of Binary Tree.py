# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findLeaves(self, root: TreeNode) -> List[List[int]]:
        result = []
        def height(root):
            if root is None:
                return -1
            leftHeight = height(root.left)
            rightHeight = height(root.right)
            h = 1 + max(leftHeight, rightHeight)
            if len(result) <= h:
                result.append([])
            result[h].append(root.val)
            return h
        height(root)
        return result
