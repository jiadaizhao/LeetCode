# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        St = []
        first = second = prev = None
        curr = root
        while St or curr:
            if curr:
                St.append(curr)
                curr = curr.left
            else:
                curr = St.pop()
                if prev and prev.val > curr.val:
                    if first is None:
                        first = prev
                    second = curr
                prev = curr
                curr = curr.right
        first.val, second.val = second.val, first.val
