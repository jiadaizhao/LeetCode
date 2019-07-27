# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        td = set(to_delete)
        result = []
        def dfs(root, prevDel):
            if root is None:
                return None

            if root.val in td:
                dfs(root.left, True)
                dfs(root.right, True)
                return None
            else:
                if prevDel == True:
                    result.append(root)
                root.left = dfs(root.left, False)
                root.right = dfs(root.right, False)
                return root           

        dfs(root, True)
        return result
