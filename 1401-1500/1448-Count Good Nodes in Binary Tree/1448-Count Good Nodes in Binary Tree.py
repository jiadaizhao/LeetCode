# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(curr, maxVal):
            if curr is None:
                return 0
            count = 1 if curr.val >= maxVal else 0
            maxVal = max(maxVal, curr.val)
            return count + dfs(curr.left, maxVal) + dfs(curr.right, maxVal)
        return dfs(root, root.val)
