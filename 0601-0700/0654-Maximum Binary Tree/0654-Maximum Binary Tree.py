# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        St = []
        for num in nums:
            node = TreeNode(num)
            while St and St[-1].val < num:
                node.left = St.pop()
            if St:
                St[-1].right = node
            St.append(node)
        return St[0]
