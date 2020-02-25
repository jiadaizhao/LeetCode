# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        maxLen = 0
        def dfs(root):
            if root is None:
                return 0
            
            currLen = 1
            leftLen = dfs(root.left)
            rightLen = dfs(root.right)
            if root.left and root.left.val == root.val + 1:
                currLen += leftLen
            if root.right and root.right.val == root.val + 1:
                currLen = max(currLen, 1 + rightLen)
            nonlocal maxLen
            maxLen = max(maxLen, currLen)
            return currLen

        dfs(root)
        return maxLen