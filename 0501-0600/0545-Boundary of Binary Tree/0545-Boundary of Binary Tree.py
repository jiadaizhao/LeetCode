# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def boundaryOfBinaryTree(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        result = [root.val]
        def addLeft(root):
            if root is None or (root.left is None and root.right is None):
                return
            result.append(root.val)
            if root.left:
                addLeft(root.left)
            else:
                addLeft(root.right)
                
        def addLeaves(root):
            if root is None:
                return
            if root.left is None and root.right is None:
                result.append(root.val)
            else:
                addLeaves(root.left)
                addLeaves(root.right)
                
        def addRight(root):
            if root is None or (root.left is None and root.right is None):
                return
            if root.right:
                addRight(root.right)
            else:
                addRight(root.left)
            result.append(root.val)
            
        addLeft(root.left)
        addLeaves(root.left)
        addLeaves(root.right)
        addRight(root.right)
        return result
