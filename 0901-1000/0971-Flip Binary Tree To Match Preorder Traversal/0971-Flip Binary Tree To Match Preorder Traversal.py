# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int]) -> List[int]:
        result = []
        i = 0
        def dfs(root):
            if root is None:
                return True
            nonlocal i
            if root.val != voyage[i]:
                return False
            i += 1
            if root.left and root.left.val != voyage[i]:
                result.append(root.val)
                return dfs(root.right) and dfs(root.left)
            return dfs(root.left) and dfs(root.right)
        
        return result if dfs(root) else [-1]
