# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        def dfs(root, start):
            if root is None:
                return False
            if root.val != arr[start]:
                return False
            if start == len(arr) - 1:
                return root.left is None and root.right is None
            return dfs(root.left, start + 1) or dfs(root.right, start + 1)
        
        return dfs(root, 0)
