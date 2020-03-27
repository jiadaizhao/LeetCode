# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        arr = []
        def inorder(root):
            if root is None:
                return
            inorder(root.left)
            arr.append(root.val)
            inorder(root.right)
            
        inorder(root)
        def construct(start, end):
            if start > end:
                return None
            mid = (start + end) // 2
            root = TreeNode(arr[mid])
            root.left = construct(start, mid - 1)
            root.right = construct(mid + 1, end)
            return root
        
        return construct(0, len(arr) - 1)
