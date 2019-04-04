# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def isSame(s, t):
            if s is None or t is None:
                return s == t
            return s.val == t.val and isSame(s.left, t.left) and isSame(s.right, t.right)
        
        if s is None or t is None:
            return s == t
                
        return isSame(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
