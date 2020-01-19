# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        curr = [root]
        while curr:
            prev = curr
            curr = [child for node in prev for child in (node.left, node.right) if child]
        return sum(node.val for node in prev)
