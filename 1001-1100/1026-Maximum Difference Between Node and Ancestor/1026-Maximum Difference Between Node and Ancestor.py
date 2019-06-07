# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        maxDiff = 0
        def dfs(root, currMax, currMin):
            if root is None:
                return
            nonlocal maxDiff
            if currMax > root.val:
                maxDiff = max(maxDiff, currMax - root.val)
            if currMin < root.val:
                maxDiff = max(maxDiff, root.val - currMin)
            currMax = max(currMax, root.val)
            currMin = min(currMin, root.val)
            dfs(root.left, currMax, currMin)
            dfs(root.right, currMax, currMin)
        dfs(root, root.val, root.val)
        return maxDiff


class Solution2:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        def dfs(root, currMax, currMin):
            if root is None:
                return currMax - currMin

            currMax = max(currMax, root.val)
            currMin = min(currMin, root.val)
            return max(dfs(root.left, currMax, currMin), dfs(root.right, currMax, currMin))
        return dfs(root, root.val, root.val)
