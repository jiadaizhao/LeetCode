# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        maxAvg = 0
        def dfs(root):
            if root is None:
                return 0, 0
            nonlocal maxAvg
            leftSum, leftCount = dfs(root.left)
            rightSum, rightCount = dfs(root.right)
            s = leftSum + root.val + rightSum
            count = leftCount + 1 + rightCount
            maxAvg = max(maxAvg, s / count)
            return s, count
        dfs(root)
        return maxAvg
