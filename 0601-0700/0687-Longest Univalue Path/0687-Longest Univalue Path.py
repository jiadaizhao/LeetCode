# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        maxLen = 0
        def dfs(root):
            if root is None:
                return -1
            nonlocal maxLen
            currLen = length = 0
            if root.left:
                leftLen = dfs(root.left)
                if root.left.val == root.val:
                    currLen += 1 + leftLen
                    length = 1 + leftLen
            if root.right:
                rightLen = dfs(root.right)
                if root.right.val == root.val:
                    currLen += 1 + rightLen
                    length = max(length, 1 + rightLen)
            maxLen = max(maxLen, currLen)
            return length
        
        dfs(root)
        return maxLen
