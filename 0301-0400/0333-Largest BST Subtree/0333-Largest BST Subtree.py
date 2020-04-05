# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def largestBSTSubtree(self, root: TreeNode) -> int:
        maxCount = 0
        def dfs(root):
            if root is None:
                return True, 0, None, None
            lBST, lCount, lMinVal, lMaxVal = dfs(root.left)
            rBST, rCount, rMinVal, rMaxVal = dfs(root.right)
            if (lBST and (lMaxVal is None or root.val > lMaxVal) and
                rBST and (rMinVal is None or root.val < rMinVal)):
                currCount = lCount + 1 + rCount
                nonlocal maxCount
                maxCount = max(maxCount, currCount)
                return True, currCount, lMinVal or root.val, rMaxVal or root.val
            else:
                return False, 0, None, None
        dfs(root)
        return maxCount
