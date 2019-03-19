# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        result = []
        path = []
        def dfs(root):
            if root is None:
                return
            path.append(str(root.val))
            if root.left is None and root.right is None:
                result.append('->'.join(path))
            else:
                dfs(root.left)
                dfs(root.right)
            path.pop()
            
        dfs(root)
        return result