# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections
class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        table = collections.Counter()
        maxCount = 0
        def treeSum(root):
            nonlocal maxCount
            if root is None:
                return 0
            currSum = treeSum(root.left) + root.val + treeSum(root.right)
            table[currSum] += 1
            if table[currSum] > maxCount:
                maxCount = table[currSum]
            return currSum
        treeSum(root)
        return [k for k, v in table.items() if v == maxCount]
            