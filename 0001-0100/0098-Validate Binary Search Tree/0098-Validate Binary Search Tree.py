# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        curr = root
        St = []
        prev = None
        while St or curr:
            if curr:
                St.append(curr)
                curr = curr.left
            else:
                curr = St.pop()
                if prev and prev.val >= curr.val:
                    return False
                prev = curr
                curr = curr.right
        return True
