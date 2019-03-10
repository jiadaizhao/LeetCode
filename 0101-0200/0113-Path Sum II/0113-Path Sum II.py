# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        result = []
        path = []
        def dfs(root, sum):
            if root is None:
                return
            sum -= root.val
            path.append(root.val)
            if sum == 0 and root.left is None and root.right is None:
                result.append(path[:])
            else:
                dfs(root.left, sum)
                dfs(root.right, sum)
            path.pop()
        dfs(root, sum)
        return result
