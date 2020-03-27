# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        maxSum = 0
        def dfs(root):
            if root is None:
                return 0, True, None, None
            lSum, lBST, lMinVal, lMaxVal = dfs(root.left)
            rSum, rBST, rMinVal, rMaxVal = dfs(root.right)
            if (lBST and (lMaxVal is None or root.val > lMaxVal) and
                rBST and (rMinVal is None or root.val < rMinVal)):
                currSum = root.val + lSum + rSum
                nonlocal maxSum
                maxSum = max(maxSum, currSum)
                return currSum, True, lMinVal or root.val, rMaxVal or root.val
            else:
                return 0, False, None, None
        dfs(root)
        return maxSum
