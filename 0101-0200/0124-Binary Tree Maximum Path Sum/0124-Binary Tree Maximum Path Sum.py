# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import math
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        maxSum = -math.inf
        def dfs(root):
            nonlocal maxSum
            if root is None:
                return 0
            leftSum = max(dfs(root.left), 0)
            rightSum = max(dfs(root.right), 0)
            maxSum = max(maxSum, leftSum + root.val + rightSum)
            return max(leftSum, rightSum) + root.val
        dfs(root)
        return maxSum
